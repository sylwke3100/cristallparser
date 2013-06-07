#include "CristallValues.h"


int CristallValues::ConvertStringtoInt(string Data)
{
    if (Data.length()>0)
    {
        int digit;
        istringstream D(Data);
        D>>digit;
        return digit;
    }
    else return -1;
}
string CristallValues::ConvertInttoString(int Data)
{
    ostringstream D;
    D << Data;
    string str = D.str();
    return str;
}
int CristallValues::size()
{
    return Summary.size();
}
string CristallValues::getElement(int Id, DataType Data)
{
    switch(Data)
    {
    case DataType::Label:
        return Summary[Id][ValueType::Label];
        break;
    case DataType::Value:
        return Summary[Id][ValueType::Value];
        break;
    }
}
void  CristallValues::loadData(const map < int, map < ValueType, string > >& Data)
{
    Summary = Data;
}
