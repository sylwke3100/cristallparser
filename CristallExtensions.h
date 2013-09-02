#ifndef CRISTALLEXTENSIONS_H
#define CRISTALLEXTENSIONS_H

#include <iostream>
#include "CristallGrammar.h"
#include "CristallValues.h"
#include <dlfcn.h>
#include <string>
struct Extension
{
    std::string Name;
    typedef void (*fun)(CristallGrammar,CristallValues);
    fun parse;

};
class CristallExtensions
{
    public:
        CristallExtensions();
        void load(std::string Name);
        void parse(CristallGrammar Grammars, CristallValues Values);
    private:
        std::vector <Extension> Extensions;
};

#endif // CRISTALLEXTENSIONS_H
