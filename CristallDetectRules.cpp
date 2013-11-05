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

bool CristallDetectRules::checkAlfanum(const std::string & str)
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

bool CristallDetectRules::checkFloatnum(const std::string& str)
{
    bool digit {false};
	for (auto const c : str)
    {
        if (isdigit(c) && digit == false)
            digit = true;
        if (OPTION_SEPARATEDFLOAT == c && digit == true && isdigit(str[str.length()-1]) )
            return true;
    }
    return false;
}


