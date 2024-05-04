#include "./FunctionCall.hpp"
#include <vector>

FunctionCall::FunctionCall(Token token,IExpression* function , std::vector<IExpression*> arguments){
    this->token = token;
    this->function = function;
    this->arguments = arguments;
}

FunctionCall::FunctionCall(const FunctionCall& other){
    this->token = other.token;
    for(int i = 0 ;i<other.arguments.size();i++){
        this->arguments.push_back(other.arguments[i]->clone());
    }
}

std::string FunctionCall::getNodeType(){
    return "FunctionCall Node";
}

std::string FunctionCall::getTokenLiteral(){
    return this->token.literalValue;
}

std::string FunctionCall::getValueLiteral(){
    return this->token.literalValue;
}

std::string FunctionCall::toString(){
    std::string functionCallString = this->function->toString();
    functionCallString += '(';
    for(int i = 0 ;i<this->arguments.size();i++){
        functionCallString += this->arguments[i]->toString();
        if(i < this->arguments.size()-1){
            functionCallString += ",";
        }
    }
    functionCallString += ")";
    return functionCallString;
}

IExpression* FunctionCall::clone(){
    return new FunctionCall(*this);
}

FunctionCall::~FunctionCall(){
    for(int i = 0 ;i<arguments.size();i++){
        delete this->arguments[i];
    }
}
