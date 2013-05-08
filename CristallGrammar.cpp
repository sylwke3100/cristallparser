#include "CristallGrammar.h"

void CristallGrammar::addGrammar(string Label, string Char)
{
    if (OperationList.empty())
        OperationCount =0;
    OperationList[OperationCount][0] = Label;
    OperationList[OperationCount][1]= Char;
    OperationCount++;
    RunRule.push_back(0);
}
void CristallGrammar::addGrammarTo(string Label,string StartChar, string EndChar, int RunRuleInside)
{
    if (OperationList.empty())
        OperationCount =0;
    OperationList[OperationCount][0] = Label;
    OperationList[OperationCount][1]= StartChar;
    OperationList[OperationCount][2]= EndChar;
    OperationCount++;
    RunRule.push_back(RunRuleInside);
}
void CristallGrammar::addRule(string YourName, int Rule)
{
   cout<<Rule<<endl;
    switch(Rule){
            case CristallRuleNumbers:
                addGrammar(YourName, "#number");
                break;
            case CristallRuleWord:
                addGrammar(YourName, "#alpha");
    }
}
