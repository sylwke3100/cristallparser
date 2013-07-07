#include "CristallParser.h"

int CristallParser::searchInvoke(string& Val)
{
    if(Val.substr(0,7)=="#number") return 7;
    if (Val.substr(0,6)=="#alpha") return 6;
    if (Val.substr(0,9)=="#alpnumer") return 9;
    if (Val.substr(0,12)=="#floatnumber") return 12;
    return 0;
}

int CristallParser::detectInvoke(char& Val)
{
    if(Val == '.')
        return 3;
     if (Val == '-')
        return 4;
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

bool CristallParser::checkFloatnum(const string& str)
{
    bool digit {false};
    for(auto const c : str)
    {
        if(isdigit(c) && digit == false)
            digit = true;
        if('.' == c && digit == true)
            return true;
    }
    return false;
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
        for (auto  element = OperationList.begin() ; element!= OperationList.end(); ++element)
        {
            if (RuleTypes[element->first] == RuleType::SingleRule && RawData.substr(pos,element->second[1].length())==element->second[1])
            {
                addElement(element->second[0],element->second[1]);
                pos+=element->second[1].length();
            }
            else if (RuleTypes[element->first] == RuleType::MultiRule && RawData.substr(pos,element->second[1].length())==element->second[1])
            {
                int po =(int) RawData.find(element->second[2],pos+element->second[1].length()+1);
                if (po >pos+element->second[1].length())
                {
                    if (RunRule[element->first]==RunRuleInside::No)
                        addElement(element->second[0],RawData.substr(pos+element->second[1].length(),po-(pos+element->second[1].length())));
                    if (RunRule[element->first]==RunRuleInside::Yes)
                    {
                        addElement(element->second[0],"open ->");
                        string RawValue = RawData.substr(pos+element->second[1].length(),po-(pos+element->second[1].length()));
                        parseData(RawValue);
                        addElement(element->second[0],"close ->");
                    }
                    pos = po+element->second[2].length()-1;
                }
            }
            else if (RuleTypes[element->first] == RuleType::SpecialRule &&  detectInvoke(RawData[pos])!=0)
            {
                digitalpha.clear();
                int inv = searchInvoke(element->second[1]);
                int Limit = ConvertStringtoInt(element->second[1].substr(inv));
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
                                addElement(element->second[0], digitalpha);
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
