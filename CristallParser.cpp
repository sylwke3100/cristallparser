#include "CristallParser.h"

using namespace std;
using namespace Cristall;

void CristallParser::setOptions(Options Option)
{
    switch (Option)
    {
    case Options::ComaFloatSeparated:
        OPTION_SEPARATEDFLOAT = ',';
        break;
    case Options::DotFloatSeparated:
        OPTION_SEPARATEDFLOAT = '.';
        break;
    }

}

void CristallParser::setData(string Data)
{
    RawData = Data;
}

void  CristallParser::parseData(string RawData)
{
    string digitalpha;
    for (int pos = 0; pos < RawData.length(); pos++)
    {
        for (auto element : OperationList)
        {
            if (element.RuleTypes == RuleType::SingleRule && RawData.substr(pos, element.StartChar.length()) == element.StartChar)
            {
                addElement(element.Label, element.StartChar, ModelReciv::Normal);
                pos += element.Label.length();
            }
            else if (element.RuleTypes == RuleType::MultiRule && RawData.substr(pos, element.StartChar.length()) == element.StartChar)
            {
                int po = (int)RawData.find(element.EndChar, pos + element.StartChar.length() + 1);
                if (po > pos + element.StartChar.length())
                {
                    if (element.RunRule == RunRuleInside::No)
                    {
                        addElement(element.Label, RawData.substr(pos + element.StartChar.length(), po - (pos + element.StartChar.length())), ModelReciv::Open);
                    }
                    if (element.RunRule == RunRuleInside::Yes)
                    {
                        addElement(element.Label, "", ModelReciv::Open);
                        string RawValue = RawData.substr(pos + element.StartChar.length(), po - (pos + element.StartChar.length()));
                        parseData(RawValue);
                        addElement(element.Label, "", ModelReciv::Close);
                    }
                    pos = po + element.EndChar.length() - 1;
                }
            }
            else if (element.RuleTypes == RuleType::SpecialRule && detectInvoke(RawData[pos]) != Types::None)
            {
                digitalpha.clear();
                Rules inv = element.RuleGroup;
                int Limit = element.Limit;
                for (int id = pos; id <= RawData.length(); id++)
                {
                    switch (detectInvoke(RawData[id]))
                    {
                    case Types::Alpha:
                        if (inv == Rules::Letters || inv == Rules::AlphaNumeric)
                        {
                            digitalpha += RawData[id];
                        }
                        break;
                    case Types::Digit:
                        if (inv == Rules::Numbers || inv == Rules::FloatNumbers)
                        {
                            digitalpha += RawData[id];
                        }
                        break;
                    case Types::Coma:
                        if ((inv == Rules::FloatNumbers  || inv == Rules::Numbers) && digitalpha.length() >= 1)
                        {
                            digitalpha += OPTION_SEPARATEDFLOAT;
                        }
                        break;
                    case Types::Minus:
                        if ((inv == Rules::FloatNumbers  || inv == Rules::Numbers) && digitalpha.length() == 0)
                        {
                            digitalpha += RawData[id];
                        }
                        break;
                    case Types::None:
                        if (digitalpha.length() > 0 && (digitalpha.length() == Limit || Limit == (int)Limits::None))
                        {
                            if ((inv == Rules::AlphaNumeric && checkAlfanum(digitalpha) == true) || 
								((inv == Rules::Letters && checkAlfanum(digitalpha) == false && checkFloatnum(digitalpha) == false) 
									|| (inv == Rules::FloatNumbers && checkFloatnum(digitalpha) == true)) || 
								(inv == Rules::Numbers && checkAlfanum(digitalpha) == false && (int)digitalpha.find('.') == -1))
                            {
                                addElement(element.Label, digitalpha, ModelReciv::Normal);
                                pos = id;
                                id = RawData.length();
                            }
                            else
                            {
                                id = RawData.length();
                            }
                        }
                        break;
                    }
                }
            }

        }
    }
}

CristallValues CristallParser::run()
{
    parseData(this->RawData);
    CristallValues Vals;
    Vals.loadData(Summary);
    return Vals;
}
