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
#include "CristallGrammarModel.h"
using namespace std;

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
    vector <CristallGrammarModel> OperationList;
private:
};

#endif // CRISTALLGRAMMAR_H
