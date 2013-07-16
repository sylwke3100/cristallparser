#ifndef CRISTALLPARSER_H
#define CRISTALLPARSER_H
#include <vector>
#include <cstdlib>
#include <iostream>
#include <cctype>
#include <map>
#include "CristallHeader.h"
#include "CristallGrammar.h"
#include "CristallValues.h"
#include "CristallDetectTools.h"
using namespace std;
using namespace Cristall;

class CristallParser : public CristallGrammar, CristallValues, CristallDetectTools
{
private:
    string RawData;
    void parseData(string RawData);
public:
    void setOptions(Options Option);
    void setData(string Data);
    CristallValues run();


};

#endif // CRISTALLPARSER_H
