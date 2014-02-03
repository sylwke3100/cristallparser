#ifndef CRISTALLPARSER_H
#define CRISTALLPARSER_H

#include <vector>
#include <iostream>
#include "grammar.h"
#include "singlegrammar.h"
#include "multigrammar.h"
#include "numbersgrammar.h"
#include "cristallheader.h"

#define GrammarsList  std::vector <Grammar *>


class CristallParser{

    GrammarsList Operations;
    std::string &T;
    void pushGrammar(Grammar* G);

public:
    std::vector<CristallStack> GlobalStack;
    CristallParser(std::string &Text);
    void parse();
    void addGrammar(std::string Label, std::string Char);
    void addGrammarTo(std::string Label, std::string StartChar, std::string EndChar, Cristall::RunRuleInside Rule);
    void addRule(std::string const& YourName, CristallTypes Rule, int Limit);
};


#endif // CRISTALLPARSER_H
