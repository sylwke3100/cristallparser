#include "numbersgrammar.h"

NumbersGrammar::NumbersGrammar(std::string Label, int Limit = 0){
    this->Label = Label;
    if (Limit != 0)
        this->Limit = 0;
}
bool NumbersGrammar::isRule(std::string& Text){
    return (isdigit(Text[0]) == true || Text[0] == '-' );
}

void NumbersGrammar::parse(std::string& Text, std::vector<CristallStack>& LocalStack){
    int Element = 0;
    for (char Char:Text){
        if (isdigit(Char) || Char == '-')
            Element++;
        else
            break;
        }
    if (Limit == Element || (Limit == 0)  ){
        LocalStack.push_back(this->getResult(boost::lexical_cast<int>(Text.substr(0,Element) ) ));
        Text.erase(0,Element);
    }
}

CristallStack NumbersGrammar::getResult(int Value){
    CristallStack ResultRule;
    ResultRule.Label = this->Label;
    ResultRule.Type = CristallTypes::Number;
    ResultRule.Value = Value;
    return ResultRule;
}
