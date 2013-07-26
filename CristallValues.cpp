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
        return Summary[Id].Label;
        break;
    case DataType::Value:
        return Summary[Id].Value;
        break;
    }
    return Summary[Id].Label;
}
void  CristallValues::loadData(const vector <CristallValuesModel> & Data)
{
    Summary = Data;
}
void CristallValues::addElement(string Label, string Value)
{
    CristallValuesModel * Model = new CristallValuesModel;
    Model->Label =Label;
    Model->Value =Value;
    Summary.push_back(*Model);
    delete Model;
}
CristallValues CristallValues::search(string What, DataType Data, SearchType How)
{
    CristallValues D;
    int Index = 0;
    for(auto i : Summary)
    {
        if( (this->getElement(Index,Data) == What && How ==SearchType::FullText) || ((int)this->getElement(Index, Data).find(What)>-1 &&  How == SearchType::Inside))
        {
            D.addElement(this->getElement(Index,DataType::Label), this->getElement(Index,DataType::Value));
        }
        else if ((this->getElement(Index,Data) == What || (int)this->getElement(Index, Data).find(What)>-1 ) && How == SearchType::Any )
        {
             D.addElement(this->getElement(Index,DataType::Label), this->getElement(Index,DataType::Value));
        }
        Index++;
    }
    return D;
}
void CristallValues::clear()
{
    Summary.erase(Summary.begin(),Summary.end());
}
