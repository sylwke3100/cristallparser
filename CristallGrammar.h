#ifndef CRISTALLGRAMMAR_H
#define CRISTALLGRAMMAR_H
#include <vector>
#include <cstdlib>
#include <iostream>
#include <cctype>
#include <map>
#include "CristallHeader.h"
#include "CristallValues.h"
#include "CristallGroup.h"
using namespace std;
using namespace Cristall;

using namespace Cristall;
class CristallGrammar: public CristallGroup
{
public:
    CristallGrammar();
    void addGrammar(string Label,string Char);
    void addGrammar(int GroupID,string Char);
    void addGrammarTo(string Label, string StartChar, string EndChar,RunRuleInside Rule);
    void addGrammarTo(int GroupID, string StartChar, string EndChar,RunRuleInside Rule);
    void addRule(string const& YourName, Cristall::Rules Rule, int Limit);

protected:
    int OperationCount;
    map <int, map<int, string> > OperationList;
    vector <RunRuleInside> RunRule;
private:
};

#endif // CRISTALLGRAMMAR_H
