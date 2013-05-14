#include "CristallParser.h"


void CristallParser::addElement(string Label, string Value)
{
	int c = Summary.size();
	Summary[c]['Label'] =Label;
	Summary[c]['Value'] =Value;
}
int CristallParser::searchInvoke(string& Val)
{
	if(Val.substr(0,7)=="#number") return 7;
	if (Val.substr(0,6)=="#alpha") return 6;
	if (Val.substr(0,9)=="#alpnumer") return 9;
	return 0;
}
int CristallParser::detectInvoke(char& Val)
{
	if(isdigit(Val))
		return 7;
	if(isalpha(Val))
		return 6;
	return 0;
}
int CristallParser::checkAlfanum(string& Value)
{
	int alpha = 0;
	int num = 0;
	for(int i =0; i<Value.length(); i++)
	{
		if (isalpha(Value[i])) alpha++;
		else if (isdigit(Value[i])) num++;
	}
	if(alpha>0 and num>0) return 1;
	return 0;
}
void CristallParser::setData(string Data)
{
	RawData = Data;
}
void  CristallParser::parseData(string RawData)
{
	string digitalpha;
	for (int pos = 0; pos<RawData.length(); pos++)
	{
		for (int i =0; i<OperationList.size(); i++)
		{
			if (OperationList[i].size()==2 and RawData.substr(pos,OperationList[i][1].length())==OperationList[i][1])
			{
				addElement(OperationList[i][0],OperationList[i][1]);
				pos+=OperationList[i][1].length()-1;
			}
			else if (OperationList[i].size()==3 and RawData.substr(pos,OperationList[i][1].length())==OperationList[i][1])
			{
				int po =(int) RawData.find(OperationList[i][2],pos+OperationList[i][1].length()+1);
				if (po >pos+OperationList[i][1].length())
				{
					if (RunRule[i]==CristallRunNoGrammarInside)
						addElement(OperationList[i][0],RawData.substr(pos+OperationList[i][1].length(),po-(pos+OperationList[i][1].length())));
					if (RunRule[i]==CristallRunGrammarInside)
					{
						addElement(OperationList[i][0],"open ->");
						string RawValue = RawData.substr(pos+OperationList[i][1].length(),po-(pos+OperationList[i][1].length()));
						parseData(RawValue);
						addElement(OperationList[i][0],"close ->");
					}
					pos = po+OperationList[i][2].length()-1;
				}
			}
			else if (searchInvoke(OperationList[i][1])>=5)
			{
				digitalpha.clear();
				int inv = searchInvoke(OperationList[i][1]);
				int Limit = Vals.ConvertStringtoInt(OperationList[i][1].substr(inv));
				for (int id = pos; id<=RawData.length(); id++)
				{
					if( (inv==9 and detectInvoke(RawData[id])== 6 or detectInvoke(RawData[id])==7 ) or detectInvoke(RawData[id])==inv and id <RawData.length())
					{
						digitalpha+=RawData[id];
					}
					else
					{
						if ( digitalpha.length()>0 and ( digitalpha.length() == Limit or Limit == CristallNoLimit)  and (inv!= 9 or ( inv == 9 and checkAlfanum(digitalpha) == true)  ) )
						{
								addElement(OperationList[i][0], digitalpha);
								pos = id;
						}
						break;
					}
				}
			}

		}
	}
}
map < int, map < const char, string > > CristallParser::run()
{
	parseData(this->RawData);
	return Summary;
}
