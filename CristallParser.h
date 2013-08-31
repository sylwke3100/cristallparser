#ifndef CRISTALLPARSER_H
#define CRISTALLPARSER_H

#include <string>

#include "CristallHeader.h"
#include "CristallGrammar.h"
#include "CristallValues.h"
#include "CristallDetectRules.h"

class CristallParser : public CristallGrammar, CristallValues, CristallDetectRules
{
private:
    std::string RawData;
    bool isAnyNumbers(Cristall::Rules Rule);
    void parseData(std::string RawData);
    void parseSingleRule(CristallGrammarModel Model, int &CurrentPosiotion);
    void parseMultiRule(CristallGrammarModel Model, int &CurrentPosiotion);
public:
    void setOptions(Cristall::Options Option);
    void setData(std::string Data);
    CristallValues run();
};

#endif // CRISTALLPARSER_H
