#include "CristallExtensions.h"

CristallExtensions::CristallExtensions()
{
    //ctor
}


void CristallExtensions::load(std::string Name)
{
        const char* filename = Name.c_str();
        void * lib = dlopen(filename, RTLD_LAZY);
         if (!lib)
         {
         std::cout<<"Load false";

         }
        typedef void (*Funcion)(CristallGrammar,CristallValues);
        Funcion parse = (Funcion)dlsym(lib, "parse");
        Extension E;
        E.Name = Name;
        E.parse = parse;
        Extensions.push_back(E);

}
void CristallExtensions::parse(CristallGrammar Grammars, CristallValues Values)
{
    Extensions[0].parse(Grammars, Values);
}
