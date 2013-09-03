#include "CristallExtensions.h"

CristallExtensions::CristallExtensions()
{
    //ctor
}


void CristallExtensions::load(std::string Name)
{
    Name = "libcristallparser-"+Name+".so";
    const char* filename = Name.c_str();
    void * lib = dlopen(filename, RTLD_LAZY);
    if (!lib)
    {
        std::cout<<"Load false";
        Load = 0;
    }
    else
    {
        Load = 1;
        typedef void (*Funcion)(std::vector <CristallGrammarModel>,CristallValues, std::string);
        Funcion parse = (Funcion)dlsym(lib, "parse");
        Extension E;
        E.Name = Name;
        E.parse = parse;
        Extensions.push_back(E);
    }

}
void CristallExtensions::parse(std::vector <CristallGrammarModel> Grammars, CristallValues Values,std:: string RawData)
{
    if(!Extensions.empty())
        Extensions[0].parse(Grammars, Values, RawData);
}
bool CristallExtensions::isLoad()
{
        return Load;

}
