#ifndef CRISTALLGRAMMARMOEL_H
#define CRISTALLGRAMMARMOEL_H

#include <vector>
#include <cstdlib>
#include <iostream>
#include <cctype>
#include <map>
#include <string>

#include "CristallHeader.h"

using namespace Cristall;
using namespace std;
class CristallGrammarModel
{

public:
    RuleType RuleTypes;
    int Limit;
    Rules RuleGroup;
    string Label;
    string StartChar;
    string EndChar;
    RunRuleInside RunRule;

};
#endif
