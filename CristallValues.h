#ifndef CRISTALLVALUES_H
#define CRISTALLVALUES_H

#include <string>
#include <vector>

#include "CristallHeader.h"
#include "CristallValuesModel.h"

struct CristallValues
{
    int size();
    std::string getElement(int Id, Cristall::DataType Data);
    void loadData(const std::vector<CristallValuesModel>& Data);
    CristallValues search(std::string What, Cristall::DataType Data, Cristall::SearchType How);
    void addElement(std::string Label, std::string Value, ModelReciv Reciv);
    void clear();
    std::vector<CristallValuesModel> Summary;
};

#endif // CRISTALLVALUES_H
