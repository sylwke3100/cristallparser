#ifndef CRISTALLGRAMMAR_H
#define CRISTALLGRAMMAR_H

#include <string>
#include <vector>

#include "CristallHeader.h"
#include "CristallValues.h"
#include "CristallGroup.h"
#include "CristallGrammarModel.h"

class CristallGrammar : public CristallGroup
{
public:
    void addGrammar(std::string Label, std::string Char);
    void addGrammarByGroup(int GroupID, std::string Char);
    void addGrammarTo(std::string Label, std::string StartChar, std::string EndChar, Cristall::RunRuleInside Rule);
    void addGrammarToByGroup(int GroupID, std::string StartChar, std::string EndChar, Cristall::RunRuleInside Rule);
    void addRule(std::string const& YourName, Cristall::Rules Rule, int Limit);

protected:
    std::vector<CristallGrammarModel> OperationList;
};

#endif // CRISTALLGRAMMAR_H
