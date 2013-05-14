#include <iostream>
#include "CristallParser.h"
#include <vector>
#include <map>

using namespace std;
using namespace Cristall;

int main()
{
	map <int, map<string,string > > c;
	map < int, map < const char, string > > Dd;
	CristallParser D;
	D.addRule("numbers", Rules::Numbers, CristallNoLimit);
	D.addRule("word", Rules::Letters, CristallNoLimit);
	D.setData("    Test word number 2555   ");
	Dd = D.run();
	for(int i =0; i<Dd.size(); i++)
	{
		cout<<Dd[i]['Label']<<" "<<Dd[i]['Value']<<endl;
	}
	return 0;
}
