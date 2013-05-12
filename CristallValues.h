#ifndef CRISTALLVALUES_H
#define CRISTALLVALUES_H
#include <map>
#include <iostream>
#include <cctype>
#include <map>
#include <sstream>
using namespace std;

class CristallValues
{
public:
    int ConvertStringtoInt(string Data);
    string ConvertInttoString(int Data);
protected:
    map < int, map < const char, string > > Summary;
private:
};

#endif // CRISTALLVALUES_H
