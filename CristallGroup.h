#ifndef CRISTALLGROUP_H
#define CRISTALLGROUP_H

#include <string>
#include <vector>

class CristallGroup
{
public:
    void addGroup(std::string GroupName);
    std::string getGroup(int GroupID);

protected:
    std::vector<std::string> GroupList;

private:
    bool isGroup(std::string GroupName);
};

#endif // CRISTALLGROUP_H
