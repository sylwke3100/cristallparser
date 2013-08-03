#ifndef CRISTALLVALUESMODEL
#define CRISTALLVALUESMODEL

#include <string>

#include "CristallHeader.h"

using namespace Cristall;
using namespace std;

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
