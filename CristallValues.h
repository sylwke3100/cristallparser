#ifndef CRISTALLVALUES_H
#define CRISTALLVALUES_H
#include <map>
#include <iostream>
#include <cctype>
#include <map>
#include <sstream>
#include "CristallHeader.h"

using namespace std;
using namespace Cristall;

class CristallValues
{
public:
    enum class ValueType;

    int ConvertStringtoInt(string Data);
    int size();
    string ConvertInttoString(int Data);
    string getElement(int Id, DataType Data);
    void loadData(map<int, map<ValueType, string> > Data);

    enum class ValueType{
        Label,
        Value
    };

protected:
    map < int, map < ValueType, string > > Summary;
private:
};

#endif // CRISTALLVALUES_H
