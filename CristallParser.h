#ifndef CRISTALLPARSER_H
#define CRISTALLPARSER_H
#include <vector>
#include <cstdlib>
#include <iostream>
#include <cctype>
#include <map>
#include "CristallHeader.h"
#include "CristallGrammar.h"
#include "CristallValues.h"
using namespace std;
using namespace Cristall;

class CristallParser : public CristallGrammar, CristallValues
{
private:
    string RawData;
    void parseData(string RawData);
    int searchInvoke(string& Val);
    int detectInvoke(char& Val);
    bool checkAlfanum(const string &str);
    bool checkFloatnum(const string &str);
public:
    void setData(string Data);
    CristallValues run();


};

#endif // CRISTALLPARSER_H
