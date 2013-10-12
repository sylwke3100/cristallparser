#include "CristallParser.h"

using namespace std;
using namespace Cristall;

void CristallParser::setOptions(Cristall::Options Option)
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

void CristallParser::setData(std::string Data)
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
            string RawValue = RawData.substr(CurrentPosiotion + Model.StartChar.length(), EndCharPosition - (CurrentPosiotion + Model.StartChar.length()) );
            parseData(RawValue);
            addElement(Model.Label, ModelReciv::Close);
        }
    CurrentPosiotion = EndCharPosition + Model.EndChar.length() - 1;
}

void CristallParser::parseAnySpecialRule(CristallGrammarModel Model, int &CurrentPosiotion)
{
    string ResultString;
    Rules CurrentElementRule = Model.RuleGroup;
    for (int Index = CurrentPosiotion; Index <= RawData.length(); Index++)
    {
        switch (detectInvoke(RawData[Index]))
        {
        case Types::Alpha:
            if (CurrentElementRule == Rules::Letters || CurrentElementRule == Rules::AlphaNumeric )
                ResultString += RawData[Index];
            break;
        case Types::Digit:
            if (isAnyNumbers(CurrentElementRule) )
                ResultString += RawData[Index];
            break;
        case Types::Coma:
            if ((CurrentElementRule == Rules::FloatNumbers ) && ResultString.length() >= 1)
                ResultString += OPTION_SEPARATEDFLOAT;
            break;
        case Types::Minus:
            if (isAnyNumbers(CurrentElementRule) && ResultString.empty())
                ResultString += RawData[Index];
            break;
        case Types::None:
            if (ResultString.length() > 0 && (ResultString.length() == Model.Limit || Model.Limit == (int)Limits::None))
            {
                if ((CurrentElementRule == Rules::AlphaNumeric && checkAlfanum(ResultString) == true) ||
                        ((CurrentElementRule == Rules::Letters && checkAlfanum(ResultString) == false && checkFloatnum(ResultString) == false)
                         || (CurrentElementRule == Rules::FloatNumbers && checkFloatnum(ResultString) == true)) ||
                        (CurrentElementRule == Rules::Numbers && checkAlfanum(ResultString) == false && (int)ResultString.find(OPTION_SEPARATEDFLOAT) == -1))
                {
                    addElement(Model.Label, ResultString, ModelReciv::Normal);
                    CurrentPosiotion = Index;
                    break;
                }
                else
                    Index = RawData.length();
            }
            break;
        }
    }
}

void  CristallParser::parseData(std::string RawData)
{
    for (int Position = 0; Position < RawData.length(); Position++)
    {
        for (auto element : OperationList)
        {
            if (isSingleRule(element, RawData, Position))
                parseSingleRule(element,Position);
            else if (isMultiRule(element, RawData, Position))
                parseMultiRule(element, Position);
            else if (element.RuleTypes == RuleType::SpecialRule && detectInvoke(RawData[Position]) != Types::None)
                parseAnySpecialRule(element, Position);
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
