#include "CristallGroup.h"

using namespace std;

void CristallGroup::addGroup(string GroupName)
{
    if (this->isGroup(GroupName) == false && GroupName != "[empty]")
        GroupList.push_back(GroupName);
}

string CristallGroup::getGroup(int GroupID)
{
    if (GroupID > -1 && GroupID < GroupList.size())
        return GroupList[GroupID];
    else
        return "[empty]";
}

int CristallGroup::getIdGroup(std::string GroupName)
{
    int Index = 0;
    for (auto element = GroupList.begin(); element != GroupList.end(); ++element)
    {
        if (*element == GroupName)
            return std::distance(GroupList.begin(), element);
    }
    return -1;
}

bool CristallGroup::isGroup(string GroupName)
{
    vector<string>::iterator element;
    for (auto element: GroupList)
    {
        if (element == GroupName)
            return true;
    }
    return false;
}
