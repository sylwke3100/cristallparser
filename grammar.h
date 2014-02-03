#ifndef GRAMMAR_H
#define GRAMMAR_H
#include <iostream>
#include <vector>
#include "cristallstack.h"

class Grammar{
public:
    std::string Label;
    virtual bool isRule(std::string& Text) = 0;
    virtual void parse(std::string& Text, std::vector<CristallStack>& Stack ) = 0;
};

#endif // GRAMMAR_H
