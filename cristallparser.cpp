#include "cristallparser.h"

CristallParser::CristallParser(std::string &Text): T(Text){

}

void CristallParser::parse(){

    while (this->T.size()>0){
        bool detectRule = 0;
        for (auto El: Operations)
            if(El->isRule(this->T)){
                El->parse(this->T, this->GlobalStack);
                detectRule = 1;
            }
        if (!detectRule)
            this->T.erase(this->T.begin());
     }
}
void CristallParser::pushGrammar(Grammar *G){
    Operations.push_back(G);
}

void CristallParser::addGrammar(std::string Label, std::string Char){
    Operations.push_back(new SingleGrammar(Label, Char));
}

void CristallParser::addGrammarTo(std::string Label, std::string StartChar, std::string EndChar, Cristall::RunRuleInside Rule){
    Operations.push_back(new MultiGrammar(Label, StartChar, EndChar));
}

void CristallParser::addRule(std::string const& YourName, CristallTypes Rule, int Limit){
    switch(Rule){
        case CristallTypes::Number:
            Operations.push_back(new NumbersGrammar(YourName, Limit));
        }
}
