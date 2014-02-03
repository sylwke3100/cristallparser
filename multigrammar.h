#ifndef MULTIGRAMMAR_H
#define MULTIGRAMMAR_H

#include <iostream>
#include "grammar.h"
#include "cristallstack.h"
class MultiGrammar : public Grammar{
    std::string StartText;
    std::string EndText;
public:
    MultiGrammar(std::string Label, std::string StartChar, std::string EndChar);
    bool isRule(std::string &Text);
    void parse(std::string& Text, std::vector<CristallStack>& LocalStack);

};

#endif // MULTIGRAMMAR_H
