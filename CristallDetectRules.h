#ifndef CRISTALLDETECTTOOLS_H
#define CRISTALLDETECTTOOLS_H

#include <string>

#include "CristallHeader.h"
#include "CristallGrammarModel.h"
class CristallDetectRules
{
public:
    enum class Types
    {
        Coma,
        Minus,
        Alpha,
        Digit,
        None
    };
    Types detectInvoke(char Val);
    bool checkAlfanum(const std::string& str);
    bool checkFloatnum(const std::string& str);
    char OPTION_SEPARATEDFLOAT = '.';
};

#endif // CRISTALLDETECTTOOLS_H
