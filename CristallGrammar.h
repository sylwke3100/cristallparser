#ifndef CRISTALLGRAMMAR_H
#define CRISTALLGRAMMAR_H
#include <vector>
#include <cstdlib>
#include <iostream>
#include <cctype>
#include <map>
using namespace std;

class CristallGrammar
{
public:
    void addGrammar(string Label,string Char);
    void addGrammarTo(string Label, string StartChar, string EndChar, int RunRuleInside);
    void addRule(string YourName, int Rule);
protected:
    int OperationCount;
    int Options[2];
    string Options_name[2];
    map <int, map<int, string> > OperationList;
    vector <int> RunRule;
private:
};

#endif // CRISTALLGRAMMAR_H
