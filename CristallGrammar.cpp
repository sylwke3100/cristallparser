#include "CristallGrammar.h"

using namespace std;
using namespace Cristall;

void CristallGrammar::addGrammar(string Label, string Char)
{
    CristallGrammarModel OperationElement(RuleType::SingleRule, Rules::None, Label, Char, "",RunRuleInside::No, 0);
   OperationList.push_back(OperationElement);
}

void CristallGrammar::addGrammar(int GroupID, string Char)
{
    string GroupName = getGroup(GroupID);
    if (GroupName != "[empty]")
    {
        addGrammar(GroupName, Char);
    }
}

void CristallGrammar::addGrammarTo(string Label, string StartChar, string EndChar, RunRuleInside Rule)
{
   CristallGrammarModel OperationElement(RuleType::MultiRule, Rules::None, Label, StartChar, EndChar, Rule, 0);
   OperationList.push_back(OperationElement);
}

void CristallGrammar::addGrammarTo(int GroupID , string StartChar, string EndChar, RunRuleInside Rule)
{
    string GroupName = getGroup(GroupID);
    if (GroupName != "[empty]")
    {
        addGrammarTo(GroupName , StartChar, EndChar, Rule);
    }
}

void CristallGrammar::addRule(string const& YourName, Rules Rule, int Limit)
{
    CristallGrammarModel OperationElement(RuleType::SpecialRule, Rule, YourName, "", "", RunRuleInside::No, Limit);
   OperationList.push_back(OperationElement);
}
