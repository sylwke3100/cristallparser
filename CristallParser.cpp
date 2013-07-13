#include "CristallParser.h"


void CristallParser::setData(string Data)
{
    RawData = Data;
}

void  CristallParser::parseData(string RawData)
{
    string digitalpha;
    for (int pos = 0; pos<RawData.length(); pos++)
    {
        for (auto  element : OperationList)
        {
            if (element.RuleTypes == RuleType::SingleRule && RawData.substr(pos,element.StartChar.length())==element.StartChar)
            {
                addElement(element.Label,element.StartChar);
                pos+=element.Label.length();
            }
            else if (element.RuleTypes == RuleType::MultiRule && RawData.substr(pos,element.StartChar.length())==element.StartChar)
            {
                int po =(int) RawData.find(element.EndChar, pos+element.StartChar.length()+1);
                if (po >pos+element.StartChar.length())
                {
                    if (element.RunRule==RunRuleInside::No)
                        addElement(element.Label,RawData.substr(pos+element.StartChar.length(),po-(pos+element.StartChar.length())));
                    if (element.RunRule==RunRuleInside::Yes)
                    {
                        addElement(element.Label,"open ->");
                        string RawValue = RawData.substr(pos+element.StartChar.length(),po-(pos+element.StartChar.length()));
                        parseData(RawValue);
                        addElement(element.Label,"close ->");
                    }
                    pos = po+element.EndChar.length()-1;
                }
            }
            else if (element.RuleTypes == RuleType::SpecialRule &&  detectInvoke(RawData[pos])!=0)
            {
                digitalpha.clear();
                int inv = (int)searchInvoke(element.RuleGroup);
                int Limit = element.Limit;
                for (int id = pos; id<=RawData.length(); id++)
                {
                    int currentinv =  detectInvoke(RawData[id]);
                    switch(currentinv)
                    {
                    case 6:
                        if(inv == 6 || inv == 9)
                            digitalpha+= RawData[id];
                            break;
                    case 7:
                        if(inv == 7 || inv == 12)
                            digitalpha+= RawData[id];
                            break;
                    case 3:
                        if(( inv == 12  || inv == 7 ) && digitalpha.length()>=1)
                            digitalpha+= ".";
                            break;
                    case 4:
                        if(( inv == 12  || inv == 7 )&& digitalpha.length()==0)
                            digitalpha+= RawData[id];
                            break;
                    default:
                        if(digitalpha.length()>0 && (digitalpha.length()==Limit || Limit==(int)Limits::None) )
                        {
                            if( (inv == 9 && checkAlfanum(digitalpha)==true ) || (( inv ==6  && checkAlfanum(digitalpha)==false && checkFloatnum(digitalpha)==false) || (inv == 12 && checkFloatnum(digitalpha)==true) ) || (inv ==7 && checkAlfanum(digitalpha)==false && (int)digitalpha.find('.')==-1))
                            {
                                addElement(element.Label, digitalpha);
                                pos = id;
                                id = RawData.length();
                            }
                            else
                                id = RawData.length();

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
