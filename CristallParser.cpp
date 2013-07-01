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
    if(Val == '-')
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

void CristallParser::setData(string Data)
{
    RawData = Data;
}

void  CristallParser::parseData(string RawData)
{
    string digitalpha;
    for (int pos = 0; pos<RawData.length(); pos++)
    {
        for (auto  element = OperationList.begin() ;element!= OperationList.end(); ++element)
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
                    int courrentinv =  detectInvoke(RawData[id]);
                    switch(inv)
                    {
                    case 6:
                        if(courrentinv==6)
                            digitalpha+=RawData[id];
                        break;
                    case 7:
                        if(courrentinv==7)
                            digitalpha+=RawData[id];
                        else if (courrentinv== 4 && digitalpha.length()==0)
                            digitalpha+=RawData[id];
                        break;
                    case 9:
                        if(courrentinv==7 || courrentinv==6)
                            digitalpha+=RawData[id];
                        break;
                    }
                    if(courrentinv == 0 && digitalpha.length()>0 && (digitalpha.length()==Limit || Limit==(int)Limits::None) )
                    {
                        if( (inv == 9 && checkAlfanum(digitalpha)==true ) || ( inv!=9 && checkAlfanum(digitalpha)==false) )
                        {
                            addElement(element->second[0], digitalpha);
                            pos = id;
                            break;
                        }
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
