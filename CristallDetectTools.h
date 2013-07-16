#ifndef CRISTALLDETECTTOOLS_H
#define CRISTALLDETECTTOOLS_H
#include <vector>
#include <cstdlib>
#include <iostream>
#include <cctype>
#include <map>
#include "CristallHeader.h"
using namespace std;
using namespace Cristall;
class CristallDetectTools
{
protected:
    int searchInvoke(Rules Rule);
    int detectInvoke(char& Val);
    bool checkAlfanum(const string &str);
    bool checkFloatnum(const string &str);
    char OPTION_SEPARATEDFLOAT = '.';
};

#endif // CRISTALLDETECTTOOLS_H
