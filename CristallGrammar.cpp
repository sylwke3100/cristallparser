#include "CristallGrammar.h"

using namespace std;
using namespace Cristall;

void CristallGrammar::addGrammar(std::string Label, std::string Char)
{
    CristallGrammarModel OperationElement(RuleType::SingleRule, Rules::None, Label, Char, "",RunRuleInside::No, 0);
   OperationList.push_back(OperationElement);
}

void CristallGrammar::addGrammarByGroup(int GroupID, std::string Char)
{
    string GroupName = getGroup(GroupID);
    if (GroupName != "[empty]")
        addGrammar(GroupName, Char);
}

void CristallGrammar::addGrammarTo(std::string Label, std::string StartChar, std::string EndChar, Cristall::RunRuleInside Rule)
{
   CristallGrammarModel OperationElement(RuleType::MultiRule, Rules::None, Label, StartChar, EndChar, Rule, 0);
   OperationList.push_back(OperationElement);
}

void CristallGrammar::addGrammarToByGroup(int GroupID , std::string StartChar, std::string EndChar, Cristall::RunRuleInside Rule)
{
    string GroupName = getGroup(GroupID);
    if (GroupName != "[empty]")
        addGrammarTo(GroupName , StartChar, EndChar, Rule);
}

void CristallGrammar::addRule(std::string const& YourName, Cristall::Rules Rule, int Limit)
{
    CristallGrammarModel OperationElement(RuleType::SpecialRule, Rule, YourName, "", "", RunRuleInside::No, Limit);
   OperationList.push_back(OperationElement);
}
