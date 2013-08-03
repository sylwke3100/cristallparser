#ifndef CRISTALLGROUP_H
#define CRISTALLGROUP_H

#include <vector>
#include <cstdlib>
#include <iostream>
#include <cctype>
#include <map>

using namespace std;

class CristallGroup
{
public:
    void addGroup(string GroupName);
    string getGroup(int GroupID);
protected:
    vector <string> GroupList;
private:
    bool isGroup(string GroupName);
};

#endif // CRISTALLGROUP_H
