#include "CristallDetectTools.h"

int CristallDetectTools::searchInvoke(string& Val)
{
    if(Val.substr(0,7)=="#number") return 7;
    if (Val.substr(0,6)=="#alpha") return 6;
    if (Val.substr(0,9)=="#alpnumer") return 9;
    if (Val.substr(0,12)=="#floatnumber") return 12;
    return 0;
}

int CristallDetectTools::detectInvoke(char& Val)
{
    if(Val == '.')
        return 3;
     if (Val == '-')
        return 4;
    if(isdigit(Val))
        return 7;
    if(isalpha(Val))
        return 6;
    return 0;
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
