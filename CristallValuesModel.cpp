#include "CristallValuesModel.h"

CristallValuesModel::CristallValuesModel(std::string Label, ModelReciv Type)
{
    this-> Label = Label;
    this-> Type = Type;
}

void CristallValuesModel::setValue(std::string Value)
{
    this->Value = Value;
}

