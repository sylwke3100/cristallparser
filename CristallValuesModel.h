#ifndef CRISTALLVALUESMODEL
#define CRISTALLVALUESMODEL

#include <string>

enum class ModelReciv
{
    Normal,
    Open,
    Close
};

struct CristallValuesModel
{
    std::string Value;
    std::string Label;
    ModelReciv Type;
};

#endif
