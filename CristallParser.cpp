#include "CristallParser.h"




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

bool CristallParser::checkAlfanum(string const& str)
{
    bool alpha {false};
    bool numerical {false};
    for(auto const c : str)
    {
        if(!alpha && isalpha(c)) alpha = true;
        else if(!numerical && isdigit(c)) numerical = true;
    }
    return numerical && alpha;
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
                pos+=OperationList[i][1].length();
            }
            else if (OperationList[i].size()==3 and RawData.substr(pos,OperationList[i][1].length())==OperationList[i][1])
            {
                int po =(int) RawData.find(OperationList[i][2],pos+OperationList[i][1].length()+1);
                if (po >pos+OperationList[i][1].length())
                {
                    if (RunRule[i]==RunRuleInside::No)
                        addElement(OperationList[i][0],RawData.substr(pos+OperationList[i][1].length(),po-(pos+OperationList[i][1].length())));
                    if (RunRule[i]==RunRuleInside::Yes)
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
                int Limit = ConvertStringtoInt(OperationList[i][1].substr(inv));
                for (int id = pos; id<=RawData.length(); id++)
                {
                    if((inv == 9 and (detectInvoke(RawData[id])== 6 or detectInvoke(RawData[id]) == 7)) or ( detectInvoke(RawData[id])==inv and id <RawData.length())
                      )
                    {
                        digitalpha+=RawData[id];
                    }
                    else
                    {
                        if ( digitalpha.length()>0 and ( digitalpha.length() == Limit or Limit == (int)Limits::None)  and (inv!= 9 or ( inv == 9 and checkAlfanum(digitalpha) == true)  ) )
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

CristallValues CristallParser::run()
{
    parseData(this->RawData);
    CristallValues Vals;
    Vals.loadData(Summary);
    return Vals;
}
