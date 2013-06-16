#include "CristallGrammar.h"

using namespace std;
using namespace Cristall;

CristallGrammar::CristallGrammar() : OperationCount {0}
{
}

void CristallGrammar::addGrammar(string Label, string Char)
{
    OperationList[OperationCount][0] = Label;
    OperationList[OperationCount][1]= Char;
    OperationCount++;
    RunRule.push_back(RunRuleInside::No);
}
void CristallGrammar::addGrammar(int GroupID, string Char)
{
    string GroupName = getGroup(GroupID);
    addGrammar(GroupName, Char);
}

void CristallGrammar::addGrammarTo(string Label,string StartChar, string EndChar, RunRuleInside Rule)
{
    OperationList[OperationCount][0] = Label;
    OperationList[OperationCount][1]= StartChar;
    OperationList[OperationCount][2]= EndChar;
    OperationCount++;
    if( Rule == RunRuleInside::Yes || Rule == RunRuleInside::No)
        RunRule.push_back(Rule);
    else
        RunRule.push_back(RunRuleInside::Yes);
}

void CristallGrammar::addGrammarTo(int GroupID ,string StartChar, string EndChar, RunRuleInside Rule)
{
    string GroupName = getGroup(GroupID);
    addGrammarTo(GroupName , StartChar, EndChar, Rule);
}

void CristallGrammar::addRule(string const& YourName, Rules Rule, int Limit)
{
    CristallValues * temp = new CristallValues;
    string query;
    switch(Rule)
    {
    case Rules::Numbers:
        query = "#number"+temp->ConvertInttoString(Limit);
        break;
    case Rules::Letters:
        query = "#alpha"+temp->ConvertInttoString(Limit);
        break;
    case Rules::AlphaNumeric:
        query = "#alpnumer"+temp->ConvertInttoString(Limit);
        break;
    }
    if(!YourName.empty() && !query.empty())
        addGrammar(YourName, query);
    delete temp;
}
