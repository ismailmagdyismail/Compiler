#include "./BlockStatement.hpp"
#include "../../../ObjectSystem/NilValue/NilValue.hpp"

#include <iostream>

BlockStatement::BlockStatement(const BlockStatement& other){
    this->token = other.token;
    for(int i = 0 ;i<other.statements.size();i++){
        this->addStatement(other.statements[i]->clone());
    }
}

void BlockStatement::setToken(Token token){
    this->token = token ;
}

void BlockStatement::addStatement(IStatement *statement){
    this->statements.push_back(statement);
}

std::string BlockStatement::toString(){
    std::string block ;
    for(int i = 0 ;i<this->statements.size();i++){
        block += statements[i]->toString();
    }
    return block;
}

std::string BlockStatement::getNodeType(){
    return "Block Node";
}

std::string BlockStatement::getTokenLiteral(){
    return this->token.literalValue;
}

IObject* BlockStatement::objectValue(){
    return new NilValue();
}

IStatement* BlockStatement::clone(){
    return  new BlockStatement(*this);
}

BlockStatement* BlockStatement::getCopy(){
    return new BlockStatement(*this);
}

BlockStatement::~BlockStatement(){
    for(int i = 0 ;i<this->statements.size();i++){
        delete this->statements[i];
    }
}
