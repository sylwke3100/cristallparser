#ifndef CRISTALLVALUES_H
#define CRISTALLVALUES_H
#include <map>
#include <iostream>
#include <cctype>
#include <map>
#include <sstream>
#include <vector>
#include "CristallHeader.h"
#include "CristallValuesModel.h"

using namespace std;
using namespace Cristall;

class CristallValues
{
public:

    int ConvertStringtoInt(string Data);
    int size();
    string ConvertInttoString(int Data);
    string getElement(int Id, DataType Data);
    void loadData(const vector <CristallValuesModel> & Data);
    CristallValues search(string What, DataType Data, SearchType How);
    void addElement(string Label, string Value, ModelReciv Reciv);
    void clear();
    vector < CristallValuesModel > Summary;
private:
};

#endif // CRISTALLVALUES_H
