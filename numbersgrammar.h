#ifndef NUMBERSGRAMMAR_H
#define NUMBERSGRAMMAR_H

#include "grammar.h"
#include <iostream>
#include <stack>
#include "cristallstack.h"
#include "boost/lexical_cast.hpp"

class NumbersGrammar: public Grammar{
    int Limit = 0;
    CristallStack getResult(int Value);
public:
    NumbersGrammar(std::string Label, int Limit);
    bool isRule(std::string &Text);
    void parse(std::string &Text, std::vector<CristallStack>&  LocalStack);

};

#endif // NUMBERSGRAMMAR_H
