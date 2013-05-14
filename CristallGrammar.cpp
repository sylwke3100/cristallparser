#include "CristallGrammar.h"

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

void CristallGrammar::addRule(string YourName, int Rule, int Limit)
{
	CristallValues * temp = new CristallValues;
	string query;
	switch(Rule)
	{
	case CristallRuleNumbers:
		query = "#number"+temp->ConvertInttoString(Limit);
		break;
	case CristallRuleWord:
		query = "#alpha"+temp->ConvertInttoString(Limit);
		break;
	case CristallRuleAlphaNum:
		query = "#alpnumer"+temp->ConvertInttoString(Limit);
		break;
	}
	if(!YourName.empty() and !query.empty())
	addGrammar(YourName, query);
	delete temp;
}
