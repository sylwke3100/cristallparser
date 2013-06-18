#include "CristallGroup.h"


void CristallGroup::addGroup(string GroupName)
{
    if(this->isGroup(GroupName)==false and GroupName!="[empty]")
        GroupList.push_back(GroupName);
}

string CristallGroup::getGroup(int GroupID)
{
    if (GroupID>-1 and GroupID<GroupList.size())
        return GroupList[GroupID];
    else
        return "[empty]";
}

int CristallGroup::isGroup(string GroupName)
{
    int Is = false;
    vector<string>::iterator element;
    for(element = GroupList.begin(); element!=GroupList.end(); ++element)
    {
        if(*element==GroupName) return true;
    }
    return false;
}
