#include "CristallGrammar.h"




void CristallGrammar::addGrammar(string Label, string Char)
{
    CristallGrammarModel * OperationElement = new CristallGrammarModel;
    OperationElement->Label = Label;
    OperationElement->StartChar= Char;
    OperationElement->RunRule = RunRuleInside::No;
    OperationElement->RuleTypes = RuleType::SingleRule;
    OperationList.push_back(*OperationElement);
    delete OperationElement;
}
void CristallGrammar::addGrammar(int GroupID, string Char)
{
    string GroupName = getGroup(GroupID);
    if(GroupName!="[empty]")
        addGrammar(GroupName, Char);
}

void CristallGrammar::addGrammarTo(string Label,string StartChar, string EndChar, RunRuleInside Rule)
{
    CristallGrammarModel * OperationElement = new CristallGrammarModel;
    OperationElement->Label = Label;
    OperationElement->StartChar= StartChar;
    OperationElement->EndChar= EndChar;
    OperationElement->RunRule = Rule;
    OperationElement->RuleTypes = RuleType::MultiRule;
    OperationList.push_back(*OperationElement);
    delete OperationElement;
}

void CristallGrammar::addGrammarTo(int GroupID ,string StartChar, string EndChar, RunRuleInside Rule)
{
    string GroupName = getGroup(GroupID);
    if(GroupName!="[empty]")
        addGrammarTo(GroupName , StartChar, EndChar, Rule);
}

void CristallGrammar::addRule(string const& YourName, Rules Rule, int Limit)
{
    CristallGrammarModel * OperationElement = new CristallGrammarModel;
    OperationElement->Label = YourName;
    OperationElement->Limit = Limit;
    OperationElement->RuleGroup = Rule;
    OperationElement->RunRule = RunRuleInside::No;
    OperationElement->RuleTypes = RuleType::SpecialRule;
    OperationList.push_back(*OperationElement);
    delete OperationElement;
}
