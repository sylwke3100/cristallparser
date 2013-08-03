#ifndef CRISTALLHEADER_H
#define CRISTALLHEADER_H


namespace Cristall
{

enum class Rules
{
    Numbers      = 0x1,
    Letters      = 0x2,
    FloatNumbers = 0x4,
    AlphaNumeric = Rules::Numbers | Rules::Letters
};

enum class Limits
{
    None
};

enum class DataType
{
    Label,
    Value
};

enum class RunRuleInside
{
    No,
	Yes
};

enum class SearchType
{
    FullText,
    Inside,
    Any
};

enum class RuleType
{
    SingleRule,
    MultiRule,
    SpecialRule
};

enum class Options
{
    Option_ComaFloatSeparated,
    Option_DotFloatSeparated
};

}
#endif
