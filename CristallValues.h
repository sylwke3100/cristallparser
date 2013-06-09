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

    int ConvertStringtoInt(string Data);
    int size();
    string ConvertInttoString(int Data);
    string getElement(int Id, DataType Data);
    void loadData(const map<int, map<DataType, string> > & Data);
    CristallValues search(string What, DataType Data);
    void addElement(string Label, string Value);
protected:
    map < int, map < DataType, string > > Summary;
private:
};

#endif // CRISTALLVALUES_H
