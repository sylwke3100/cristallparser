#include "multigrammar.h"

MultiGrammar::MultiGrammar(std::string Label, std::string StartChar, std::string EndChar){
    this->StartText = StartChar;
    this->EndText = EndChar;
    this->Label = Label;
}

bool MultiGrammar::isRule(std::string& Text){
    return (Text.substr(0, StartText.length()) == StartText);
}

void MultiGrammar::parse(std::string& Text, std::vector<CristallStack> &LocalStack){
    std::string StartString = Text.substr(StartText.length());
    int Position = StartString.find(EndText);
    if (Position!=-1){
        CristallStack Stack;
        Stack.Label = Label;
        Stack.Type = CristallTypes::Multi;
        Stack.Value = Text.substr(StartText.length(), Position);
        LocalStack.push_back(Stack);
        Text.erase(0, Position + EndText.length());
    }
}
