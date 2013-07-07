#ifndef CRISTALLDETECTTOOLS_H
#define CRISTALLDETECTTOOLS_H
#include <vector>
#include <cstdlib>
#include <iostream>
#include <cctype>
#include <map>

using namespace std;

class CristallDetectTools
{
protected:
    int searchInvoke(string& Val);
    int detectInvoke(char& Val);
    bool checkAlfanum(const string &str);
    bool checkFloatnum(const string &str);
};

#endif // CRISTALLDETECTTOOLS_H
