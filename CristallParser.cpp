#include "CristallParser.h"

void CristallParser::addGrammar(string Label, string Char)
{
    if (OperationList.empty()) OperationCount =0;
    OperationList[OperationCount][0] = Label;
    OperationList[OperationCount][1]= Char;
    OperationCount++;
    RunRule.push_back(0);
}
void CristallParser::addGrammarTo(string Label,string StartChar, string EndChar, int RunRuleInside)
{
    if (OperationList.empty()) OperationCount =0;
    OperationList[OperationCount][0] = Label;
    OperationList[OperationCount][1]= StartChar;
    OperationList[OperationCount][2]= EndChar;
    OperationCount++;
    RunRule.push_back(RunRuleInside);
}
void CristallParser::addElement(string Label, string Value)
{
    int c = Summary.size();
    Summary[c]['Label'] =Label;
    Summary[c]['Value'] =Value;
}
void CristallParser::addRule(string YourName, int Rule)
{
    Options[Rule] = 1;
    Options_name[Rule] = YourName;
}
void CristallParser::setData(string Data)
{
    RawData = Data;
}
void  CristallParser::parseData(string RawData)
{
    string digit = "";
    string alpha = "";
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
            else if (isdigit(RawData[pos]))
            {
                digit="";
                for (int id = pos; id<=RawData.length(); id++)
                {
                    if(isdigit(RawData[id]) and id <RawData.length())
                    {
                        digit+=RawData[id];
                    }
                    else
                    {
                        if (digit.length()>0  and Options[CristallRuleNumbers]==true)
                        {
                            addElement(Options_name[CristallRuleNumbers],digit);
                        }
                        pos = id;
                        break;
                    }
                }
            }
            else if (isalpha(RawData[pos]))
            {
                alpha= "";
                for (int id = pos; id<=RawData.length(); id++)
                {
                    if(isalpha(RawData[id]) and id <RawData.length())
                    {
                        alpha+=RawData[id];
                    }
                    else
                    {
                        if (alpha.length()>0  and Options[CristallRuleWord]==true)
                        {
                            addElement(Options_name[CristallRuleWord],alpha);
                        }

                        pos = pos+alpha.length();

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
