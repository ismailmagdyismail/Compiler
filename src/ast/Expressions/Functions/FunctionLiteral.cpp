#include "./FunctionLiteral.hpp"
#include "../../../ObjectSystem/NilValue/NilValue.hpp"

#include <iostream>
#include <vector>

FunctionLiteral::FunctionLiteral(Token token,BlockStatement* blockStatement,std::vector<LValueIdentifier*>args){
    this->token = token;
    this->blockStatements = blockStatement;
    this->arguments = args;
}

FunctionLiteral::FunctionLiteral(const FunctionLiteral& other){
    this->token = other.token;
    for(int i = 0 ;i<other.arguments.size();i++){
        this->arguments.push_back(other.arguments[i]->getCopy());
    }
    this->blockStatements = other.blockStatements->getCopy();
}


std::string FunctionLiteral::toString(){
    std::string functionString = this->token.literalValue +"(";
    for(int i = 0 ;i<this->arguments.size();i++){
        functionString += this->arguments[i]->toString();
        if(i != this->arguments.size()-1){
            functionString += ",";
        }
    }
    functionString +="){";
    functionString += this->blockStatements->toString();
    functionString += "}";
    return functionString;
}

std::string FunctionLiteral::getNodeType(){
    return "Function Node";
}

std::string FunctionLiteral::getTokenLiteral(){
    return this->token.literalValue;
}

std::string FunctionLiteral::getValueLiteral(){
    return this->token.literalValue;
}

IObject* FunctionLiteral::objectValue(){
    return new NilValue();
}

IExpression* FunctionLiteral::clone(){
    return new FunctionLiteral(*this);
}

FunctionLiteral::~FunctionLiteral(){
    delete this->blockStatements;
    for(auto& arg:arguments){
        delete arg;
    }
}
