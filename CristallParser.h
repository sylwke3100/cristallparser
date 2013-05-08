#ifndef CRISTALLPARSER_H
#define CRISTALLPARSER_H
#include <vector>
#include <cstdlib>
#include <iostream>
#include <cctype>
#include <map>
#include "CristallHeader.h"

using namespace std;

class CristallParser
{
private:
    int Options[2];
    string Options_name[2];
    map <int, map<int, string> > OperationList;
    int OperationCount;
    map < int, map < const char, string > > Summary;
    string RawData;
    vector <int> RunRule;
    void addElement(string Label, string Value); // Adding Element to output map
    void parseData(string RawData);               // Parse Data from Source
public:
    void addGrammar(string Label,string Char);
    void addGrammarTo(string Label, string StartChar, string EndChar, int RunRuleInside);
    void addRule(string YourName, int Rule);
    void setData(string Data);
    map < int, map < const char, string > > run();



};

#endif // CRISTALLPARSER_H
