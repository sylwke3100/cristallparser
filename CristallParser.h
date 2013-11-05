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
    void parseData(std::string RawData);
    void parseSingleRule(CristallGrammarModel Model);
    void parseMultiRule(CristallGrammarModel Model);
    void parseAnySpecialRule(CristallGrammarModel Model);
public:
    void setOptions(Cristall::Options Option);
    void setData(std::string Data);
    CristallValues run();
};

#endif // CRISTALLPARSER_H
