#ifndef CRISTALLVALUESMODEL
#define CRISTALLVALUESMODEL
#include <map>
#include <iostream>
#include <cctype>
#include <map>
#include <sstream>
#include "CristallHeader.h"

using namespace Cristall;
using namespace std;

enum class ModelReciv
{
    Normal = 0,
    Open = 1,
    Close = 2
};

class CristallValuesModel
{

public:
    string Value;
    string Label;
    ModelReciv Type;
};

#endif
