#include <iostream>
#include "CristallParser.h"
#include <vector>
#include <map>
using namespace std;

int main()
{
	map <int, map<string,string > > c;
	map < int, map < const char, string > > Dd;
	CristallParser D;
	D.addRule("numbers", CristallRuleNumbers, CristallNoLimit);
	D.addRule("word",CristallRuleWord, CristallNoLimit);
	D.setData("    Test word number 2555   ");
	Dd = D.run();
	for(int i =0; i<Dd.size(); i++)
	{
		cout<<Dd[i]['Label']<<" "<<Dd[i]['Value']<<endl;
	}
	return 0;
}
