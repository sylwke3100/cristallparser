#include "CristallParser.h"

using namespace std;
using namespace Cristall;

void CristallParser::setOptions(Cristall::Options Option)
{
    switch (Option)
    {
    case Options::ComaFloatSeparated:
        OPTION_SEPARATEDFLOAT = ',';
        break;
    case Options::DotFloatSeparated:
        OPTION_SEPARATEDFLOAT = '.';
        break;
    }
}

void CristallParser::setData(std::string Data)
{
    RawData = Data;
}



void  CristallParser::parseData(std::string RawData)
{

}

CristallValues CristallParser::run()
{
    parseData(this->RawData);
    CristallValues Vals;
    Vals.loadData(Summary);
    return Vals;
}
