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

void CristallParser::parseSingleRule(CristallGrammarModel Model, int& CurrentPosiotion)
{
    addElement(Model.Label, Model.StartChar, ModelReciv::Normal);
    CurrentPosiotion += Model.Label.length();
}

void CristallParser::parseMultiRule(CristallGrammarModel Model, int& CurrentPosiotion)
{
    int EndCharPosition = (int)RawData.find(Model.EndChar, CurrentPosiotion + Model.StartChar.length() + 1);
    if (EndCharPosition > CurrentPosiotion + Model.StartChar.length())
        if (Model.RunRule == RunRuleInside::No)
            addElement(Model.Label, RawData.substr(CurrentPosiotion + Model.StartChar.length(), EndCharPosition - (CurrentPosiotion + Model.StartChar.length())), ModelReciv::Open);
        else if (Model.RunRule == RunRuleInside::Yes)
        {
            addElement(Model.Label, ModelReciv::Open);
            string RawValue = RawData.substr(CurrentPosiotion + Model.StartChar.length(), EndCharPosition - (CurrentPosiotion + Model.StartChar.length()));
            parseData(RawValue);
            addElement(Model.Label, ModelReciv::Close);
        }
    CurrentPosiotion = EndCharPosition + Model.EndChar.length() ;
}

bool CristallParser::isAnyNumbers(Rules Rule)
{
    if (Rule == Rules::Numbers || Rule== Rules::FloatNumbers)
        return true;
    else
        return false;
}

void  CristallParser::parseData(string RawData)
{
    string digitalpha;
    for (int pos = 0; pos < RawData.length(); pos++)
    {
        for (auto element : OperationList)
        {
            if (isSingleRule(element, RawData, pos))
                parseSingleRule(element,pos);
            else if (isMultiRule(element, RawData, pos))
                parseMultiRule(element, pos);
            else if (element.RuleTypes == RuleType::SpecialRule && detectInvoke(RawData[pos]) != Types::None)
            {
                digitalpha.clear();
                Rules CurrentElementRule = element.RuleGroup;
                int Limit = element.Limit;
                for (int id = pos; id <= RawData.length(); id++)
                {
                    switch (detectInvoke(RawData[id]))
                    {
                    case Types::Alpha:
                        if (CurrentElementRule == Rules::Letters || CurrentElementRule == Rules::AlphaNumeric)
                        {
                            digitalpha += RawData[id];
                        }
                        break;
                    case Types::Digit:
                        if (isAnyNumbers(CurrentElementRule))
                        {
                            digitalpha += RawData[id];
                        }
                        break;
                    case Types::Coma:
                        if ((CurrentElementRule == Rules::FloatNumbers ) && digitalpha.length() >= 1)
                        {
                            digitalpha += OPTION_SEPARATEDFLOAT;
                        }
                        break;
                    case Types::Minus:
                        if (isAnyNumbers(CurrentElementRule) && digitalpha.empty())
                        {
                            digitalpha += RawData[id];
                        }
                        break;
                    case Types::None:
                        if (digitalpha.length() > 0 && (digitalpha.length() == Limit || Limit == (int)Limits::None))
                        {
                            if ((CurrentElementRule == Rules::AlphaNumeric && checkAlfanum(digitalpha) == true) ||
                                    ((CurrentElementRule == Rules::Letters && checkAlfanum(digitalpha) == false && checkFloatnum(digitalpha) == false)
                                     || (CurrentElementRule == Rules::FloatNumbers && checkFloatnum(digitalpha) == true)) ||
                                    (CurrentElementRule == Rules::Numbers && checkAlfanum(digitalpha) == false && (int)digitalpha.find(OPTION_SEPARATEDFLOAT) == -1))
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
