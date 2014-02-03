#include "singlegrammar.h"

SingleGrammar::SingleGrammar(std::string Label, std::string Char){
    this->Label = Label;
    RuleWord = Char;
}

bool SingleGrammar::isRule(std::string &Text){
    return (Text.substr(0, RuleWord.length()) == RuleWord );
}

void SingleGrammar::parse(std::string &Text, std::vector<CristallStack> &LocalStack){
    CristallStack stack;
    stack.Label = this->Label;
    stack.Type = CristallTypes::Single;
    stack.Value = this->RuleWord;
    LocalStack.push_back(stack);
    Text.erase(0, RuleWord.length());
}

