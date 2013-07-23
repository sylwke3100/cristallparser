#include "CristallDetectTools.h"

int CristallDetectTools::searchInvoke(Rules Rule)
{
    if(Rule == Rules::Numbers) return 7;
    if (Rule == Rules::Letters) return 6;
    if (Rule == Rules::AlphaNumeric) return 9;
    if (Rule == Rules::FloatNumbers) return 12;
    return 0;
}

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
        if('.' == c && digit == true)
            return true;
    }
    return false;
}
