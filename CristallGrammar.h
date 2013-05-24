#ifndef CRISTALLGRAMMAR_H
#define CRISTALLGRAMMAR_H
#include <vector>
#include <cstdlib>
#include <iostream>
#include <cctype>
#include <map>
#include "CristallHeader.h"
#include "CristallValues.h"
using namespace std;

class CristallGrammar
{
public:
    CristallGrammar();
    void addGrammar(string Label,string Char);
    void addGrammarTo(string Label, string StartChar, string EndChar, int RunRuleInside);
    void addRule(string const& YourName, Cristall::Rules Rule, int Limit);

protected:
    int OperationCount;
    map <int, map<int, string> > OperationList;
    vector <int> RunRule;
private:
};

#endif // CRISTALLGRAMMAR_H
