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

class CristallParser : public CristallGrammar
{
private:
    map<int, map<ValueType, string>> Summary;
    string RawData;
    void parseData(string RawData);
    int searchInvoke(string& Val);
    int detectInvoke(char& Val);
    bool checkAlfanum(const string &str);
    CristallValues Vals;
public:
    void setData(string Data);
    CristallValues run();


};

#endif // CRISTALLPARSER_H
