#include <sstream>

#include "CristallValues.h"

using namespace std;
using namespace Cristall;


int CristallValues::size()
{
    return Summary.size();
}

string CristallValues::getElement(int Id, Cristall::DataType Data)
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

void CristallValues::loadData(const std::vector<CristallValuesModel>& Data)
{
    Summary = Data;
}

void CristallValues::addElement(std::string Label, std::string Value, ModelReciv Reciv)
{
    CristallValuesModel Model(Label, Reciv );
    if (!Value.empty())
        Model.setValue(Value);
    Summary.push_back(Model);
}

void CristallValues::addElement(std::string Label, ModelReciv Reciv)
{
    addElement(Label, "", Reciv);
}

CristallValues CristallValues::search(std::string What, Cristall::DataType Data, Cristall::SearchType How)
{
    CristallValues Result;
    int Index = 0;
    for (auto i : Summary)
    {
        if ((getElement(Index, Data) == What && How == SearchType::FullText)
                || ((int)getElement(Index, Data).find(What) > -1 && How == SearchType::Inside))
            Result.addElement(getElement(Index, DataType::Label), getElement(Index, DataType::Value), ModelReciv::Normal);
        else if ((getElement(Index, Data) == What || (int)getElement(Index, Data).find(What) > -1) && How == SearchType::Any)
            Result.addElement(getElement(Index, DataType::Label), getElement(Index, DataType::Value), ModelReciv::Normal);
        Index++;
    }
    return Result;
}

void CristallValues::clear()
{
    Summary.erase(Summary.begin(), Summary.end());
}
