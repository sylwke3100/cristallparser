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
        return Summary[Id][DataType::Label];
        break;
    case DataType::Value:
        return Summary[Id][DataType::Value];
        break;
    }
    return Summary[Id][DataType::Label];
}
void  CristallValues::loadData(const map < int, map < DataType, string > >& Data)
{
    Summary = Data;
}
void CristallValues::addElement(string Label, string Value)
{
    int c = Summary.size();
    Summary[c][DataType::Label] =Label;
    Summary[c][DataType::Value] =Value;
}
CristallValues CristallValues::search(string What, DataType Data, SearchType How)
{
    CristallValues D;
    for(auto i = Summary.begin(); i!=Summary.end(); ++i)
    {
        if( (this->getElement(i->first,Data) == What && How ==SearchType::FullText) || ((int)this->getElement(i->first, Data).find(What)>-1 &&  How == SearchType::Inside))
        {
            D.addElement(this->getElement(i->first,DataType::Label), this->getElement(i->first,DataType::Value));
        }
    }
    return D;
}
void CristallValues::clear()
{
    Summary.erase(Summary.begin(),Summary.end());
}
