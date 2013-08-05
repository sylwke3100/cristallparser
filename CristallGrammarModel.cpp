#include "CristallGrammarModel.h"

CristallGrammarModel::CristallGrammarModel(Cristall::RuleType RuleTypes,  Cristall::Rules RuleGroup, std::string Label, std::string StartChar, std::string EndChar, Cristall::RunRuleInside RunRule, int Limit)
{
    this-> RuleTypes = RuleTypes;
    this-> RuleGroup = RuleGroup;
    this-> Label  = Label;
    this-> StartChar = StartChar;
    this-> EndChar  = EndChar;
    this-> RunRule  = RunRule;
    this ->Limit   = Limit;
}
