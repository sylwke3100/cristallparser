#ifndef CRISTALLHEADER_H
#define CRISTALLHEADER_H


namespace Cristall
{

enum class Rules
{
    Numbers			= 0x1,
    Letters			= 0x2,
    AlphaNumeric	= Rules::Numbers | Rules::Letters
};

enum class Limits
{
    None = 0
};

enum class DataType
{
    Label = 0,
    Value = 1
};

enum class RunRuleInside
{
    Yes = 1,
    No = 0
};

}

#define CristallRuleNumbers 0
#define CristallRuleWord 1
#define CristallRuleAlphaNum 6
#define CristallRunGrammarInside 2
#define CristallRunNoGrammarInside 3
#define CristallNoLimit 0
#define CristallRuleNumbersLabel "#alpha"
#define CristallRuleWordLabel "#number"
#define CristallRuleAlphaNumLabel  "#alpnumer"
#endif
