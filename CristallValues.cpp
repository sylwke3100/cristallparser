#include <sstream>

#include "CristallValues.h"

using namespace std;
using namespace Cristall;


int CristallValues::size()
{
    return Summary.size();
}

string CristallValues::getElement(int Id, DataType Data)
{
    switch (Data)
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

void CristallValues::loadData(const vector<CristallValuesModel>& Data)
{
    Summary = Data;
}

void CristallValues::addElement(string Label, string Value, ModelReciv Reciv)
{
    CristallValuesModel Model(Value, Label, Reciv );
    Summary.push_back(Model);
}

CristallValues CristallValues::search(string What, DataType Data, SearchType How)
{
    CristallValues D;
    int Index = 0;
    for (auto i : Summary)
    {
        if ((getElement(Index, Data) == What && How == SearchType::FullText)
                || ((int)getElement(Index, Data).find(What) > -1 && How == SearchType::Inside))
        {
            D.addElement(getElement(Index, DataType::Label), getElement(Index, DataType::Value), ModelReciv::Normal);
        }
        else if ((getElement(Index, Data) == What || (int)getElement(Index, Data).find(What) > -1) && How == SearchType::Any)
        {
            D.addElement(getElement(Index, DataType::Label), getElement(Index, DataType::Value), ModelReciv::Normal);
        }
        Index++;
    }
    return D;
}

void CristallValues::clear()
{
    Summary.erase(Summary.begin(), Summary.end());
}
