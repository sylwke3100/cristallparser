#ifndef CRISTALLEXTENSIONS_H
#define CRISTALLEXTENSIONS_H

#include <iostream>
#include "CristallGrammar.h"
#include "CristallValues.h"
#include <dlfcn.h>
#include <string>
#include <vector>
struct Extension
{
    std::string Name;
    typedef void (*fun)(std::vector <CristallGrammarModel>,CristallValues, std::string);
    fun parse;

};
class CristallExtensions
{
    public:
        CristallExtensions();
        void load(std::string Name);
        void parse(std::vector <CristallGrammarModel> Grammars, CristallValues Values, std::string RawData);
        bool isLoad();
    private:
        std::vector <Extension> Extensions;
        int Load;
};

#endif // CRISTALLEXTENSIONS_H
