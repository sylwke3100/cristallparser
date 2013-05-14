#include "CristallGrammar.h"

using namespace std;
using namespace Cristall;

CristallGrammar::CristallGrammar() : OperationCount{0}
{
}

void CristallGrammar::addGrammar(string Label, string Char)
{
	OperationList[OperationCount][0] = Label;
	OperationList[OperationCount][1]= Char;
	OperationCount++;
	RunRule.push_back(0);
}

void CristallGrammar::addGrammarTo(string Label,string StartChar, string EndChar, int RunRuleInside)
{
	OperationList[OperationCount][0] = Label;
	OperationList[OperationCount][1]= StartChar;
	OperationList[OperationCount][2]= EndChar;
	OperationCount++;
	RunRule.push_back(RunRuleInside);
}

void CristallGrammar::addRule(string const& YourName, Rules Rule, int Limit)
{
	CristallValues * temp = new CristallValues;
	string query;
	switch(Rule)
	{
	case Rules::Numbers:
		query = "#number"+temp->ConvertInttoString(Limit);
		break;
	case Rules::Letters:
		query = "#alpha"+temp->ConvertInttoString(Limit);
		break;
	case Rules::AlphaNumeric:
		query = "#alpnumer"+temp->ConvertInttoString(Limit);
		break;
	}
	if(!YourName.empty() && !query.empty())
	addGrammar(YourName, query);
	delete temp;
}
