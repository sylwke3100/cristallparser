#ifndef CRISTALLPARSER_H
#define CRISTALLPARSER_H
#include <vector>
#include <cstdlib>
#include <iostream>
#include <cctype>
#include <map>
#include "CristallHeader.h"
#include "CristallGrammar.h"
#include "CristallValues.h"
using namespace std;

class CristallParser : public CristallGrammar
{
private:
	map<int, map<const char, string>> Summary;
	string RawData;
	void addElement(string Label, string Value);  // Adding Element to output map
	void parseData(string RawData);               // Parse Data from Source
	int searchInvoke(string& Val);
	int detectInvoke(char& Val);
	bool checkAlfanum(const string &str);
	CristallValues Vals;
public:
	void setData(string Data);
	map < int, map < const char, string > > run();


};

#endif // CRISTALLPARSER_H
