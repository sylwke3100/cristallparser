#ifndef CRISTALLPARSER_H
#define CRISTALLPARSER_H
#include <vector>
#include <cstdlib>
#include <iostream>
#include <cctype>
#include <map>
#include "CristallHeader.h"
#include "CristallGrammar.h"
using namespace std;

class CristallParser : public CristallGrammar
{
private:
    map < int, map < const char, string > > Summary;
    string RawData;
    void addElement(string Label, string Value); // Adding Element to output map
    void parseData(string RawData);               // Parse Data from Source
public:


    void setData(string Data);
    map < int, map < const char, string > > run();



};

#endif // CRISTALLPARSER_H
