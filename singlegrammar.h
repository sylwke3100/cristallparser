#ifndef SINGLEGRAMMAR_H
#define SINGLEGRAMMAR_H

#include <iostream>
#include "grammar.h"
#include <stack>
#include "cristallstack.h"
class SingleGrammar : public Grammar{
    std::string RuleWord;
public:
    SingleGrammar(std::string Label, std::string Char);
    bool isRule(std::string &Text);
    void parse(std::string &Text, std::vector<CristallStack>& LocalStack);

};

#endif // SINGLEGRAMMAR_H
