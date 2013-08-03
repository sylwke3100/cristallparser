#ifndef CRISTALLVALUES_H
#define CRISTALLVALUES_H

#include <string>
#include <vector>

#include "CristallHeader.h"
#include "CristallValuesModel.h"

struct CristallValues
{
    int ConvertStringtoInt(std::string Data);
    int size();
    std::string ConvertInttoString(int Data);
    std::string getElement(int Id, DataType Data);
    void loadData(const std::vector<CristallValuesModel>& Data);
    CristallValues search(std::string What, DataType Data, SearchType How);
    void addElement(std::string Label, std::string Value, ModelReciv Reciv);
    void clear();
    std::vector<CristallValuesModel> Summary;
};

#endif // CRISTALLVALUES_H
