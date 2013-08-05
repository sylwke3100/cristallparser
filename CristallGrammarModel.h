#ifndef CRISTALLGRAMMARMOEL_H
#define CRISTALLGRAMMARMOEL_H

#include <string>

#include "CristallHeader.h"

class CristallGrammarModel
{
public:
    Cristall::RuleType RuleTypes;
    int Limit;
    Cristall::Rules RuleGroup;
    std::string Label;
    std::string StartChar;
    std::string EndChar;
    Cristall::RunRuleInside RunRule;
    CristallGrammarModel(Cristall::RuleType RuleTypes,  Cristall::Rules RuleGroup ,std::string Label, std::string StartChar, std::string EndChar, Cristall::RunRuleInside RunRule, int Limit );
};
#endif
