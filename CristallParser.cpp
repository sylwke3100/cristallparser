#include "CristallParser.h"


void CristallParser::addElement(string Label, string Value)
{
    int c = Summary.size();
    Summary[c]['Label'] =Label;
    Summary[c]['Value'] =Value;
}
int CristallParser::searchInvoke(string Val)
{
    if(Val.substr(0,7)=="#number") return 7;
    if (Val.substr(0,6)=="#alpha") return 6;
    return 0;
}
int CristallParser::detectInvoke(char Val)
{
    if(isdigit(Val))
        return 7;
    if(isalpha(Val))
        return 6;
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
                    if(detectInvoke(RawData[id])==inv and id <RawData.length())
                    {
                        digitalpha+=RawData[id];
                    }
                    else
                    {
                        if ( digitalpha.length()>0 and ( digitalpha.length() == Limit or Limit == CristallNoLimit))
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
