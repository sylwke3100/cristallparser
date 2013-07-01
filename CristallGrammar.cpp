#include "CristallGrammar.h"



CristallGrammar::CristallGrammar() : OperationCount {0}
{
}

void CristallGrammar::addGrammar(string Label, string Char)
{
    OperationList[OperationCount][0] = Label;
    OperationList[OperationCount][1]= Char;
    OperationCount++;
    RunRule.push_back(RunRuleInside::No);
    if  (Char.substr(0,1) != "#")
        RuleTypes.push_back(RuleType::SingleRule);
    else
        RuleTypes.push_back(RuleType::SpecialRule);
}
void CristallGrammar::addGrammar(int GroupID, string Char)
{
    string GroupName = getGroup(GroupID);
    if(GroupName!="[empty]")
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
    RuleTypes.push_back(RuleType::MultiRule);
}

void CristallGrammar::addGrammarTo(int GroupID ,string StartChar, string EndChar, RunRuleInside Rule)
{
    string GroupName = getGroup(GroupID);
    if(GroupName!="[empty]")
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
    case Rules::FloatNumbers:
        query = "#floatnumber"+temp->ConvertInttoString(Limit);
        break;
    }
    if(!YourName.empty() && !query.empty())
        addGrammar(YourName, query);
    delete temp;
}
