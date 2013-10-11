#include "CristallDetectRules.h"

using namespace std;

CristallDetectRules::Types CristallDetectRules::detectInvoke(char Val)
{
    if (Val == OPTION_SEPARATEDFLOAT)
        return Types::Coma;
    if (Val == '-')
        return Types::Minus;
    if (isdigit(Val))
        return Types::Digit;
    if (isalpha(Val))
        return Types::Alpha;
    return Types::None;
}

bool CristallDetectRules::checkAlfanum(string const& str)
{
    bool alpha {false};
    bool numerical {false};
    for (auto const c : str)
    {
        if (!alpha && isalpha(c))
            alpha = true;
        else if (!numerical && isdigit(c))
            numerical = true;
    }
    return numerical && alpha;
}

bool CristallDetectRules::checkFloatnum(const string& str)
{
    bool digit {false};
	for (auto const c : str)
    {
        if (isdigit(c) && digit == false)
            digit = true;
        if (OPTION_SEPARATEDFLOAT == c && digit == true)
            return true;
    }
    return false;
}

bool CristallDetectRules::isSingleRule(CristallGrammarModel element, const std::string& RawData, int pos)
{
    if (element.RuleTypes == Cristall::RuleType::SingleRule && RawData.substr(pos, element.StartChar.length()) == element.StartChar)
        return true;
    else
        return false;
}

bool CristallDetectRules::isMultiRule(CristallGrammarModel element, const std::string& RawData, int pos)
{
    if (element.RuleTypes == Cristall::RuleType::MultiRule && RawData.substr(pos, element.StartChar.length()) == element.StartChar)
        return true;
    else
        return false;
}

bool CristallDetectRules::isAnyNumbers(Cristall::Rules Rule)
{
    if (Rule == Cristall::Rules::Numbers || Rule== Cristall::Rules::FloatNumbers)
        return true;
    else
        return false;
}
