#include "CristallDetectTools.h"



CristallDetectTools::Types CristallDetectTools::detectInvoke(char& Val)
{
    if(Val == OPTION_SEPARATEDFLOAT)
        return Types::Coma;
    if (Val == '-')
        return Types::Minus;
    if(isdigit(Val))
        return Types::Digit;
    if(isalpha(Val))
        return Types::Alpha;
    return Types::None;
}

bool CristallDetectTools::checkAlfanum(string const& str)
{
    bool alpha {false};
    bool numerical {false};
    for(auto const c : str)
    {
        if(!alpha && isalpha(c)) alpha = true;
        else if(!numerical && isdigit(c)) numerical = true;
    }
    return numerical && alpha;
}

bool CristallDetectTools::checkFloatnum(const string& str)
{
    bool digit {false};
    for(auto const c : str)
    {
        if(isdigit(c) && digit == false)
            digit = true;
        if(OPTION_SEPARATEDFLOAT == c && digit == true)
            return true;
    }
    return false;
}
