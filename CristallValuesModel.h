#ifndef CRISTALLVALUESMODEL
#define CRISTALLVALUESMODEL

#include <string>

enum class ModelReciv
{
    Normal,
    Open,
    Close
};

class CristallValuesModel
{
    public:
    std::string Value;
    std::string Label;
    ModelReciv Type;
    CristallValuesModel (std::string Value, std::string Label, ModelReciv Type);
};

#endif
