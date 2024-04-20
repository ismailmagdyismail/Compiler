#include "./If.hpp"
#include <iostream>

If::If(IExpression* condition ,BlockStatement* consequence){
    this->condition = condition;
    this->consequence = consequence;
    this->alternative = nullptr;
    this->token = TokenActions::createToken(TokenType::IF);
}

If::If(const If& other){
    this->condition = other.condition->clone();
    this->consequence = other.consequence->getCopy();
    this->alternative = other.alternative->getCopy();
    this->token = other.token;
}

void If::setAlternative(BlockStatement* alternative){
    this->alternative = alternative;
}


std::string If::toString(){
    std::string ifString = TokenActions::getTokenLiteralValue(TokenType::IF) + this->condition->toString()
    + "{"+ this->consequence->toString()+"}";
    if(this->alternative != nullptr){
        ifString += "else{";
        ifString += this->alternative->toString();
        ifString += "}";
    }
    return ifString;
}

std::string If::getNodeType(){
    return "If Node";
}

std::string If::getTokenLiteral(){
    return this->token.literalValue;
}

std::string If::getValueLiteral(){
    return this->toString();
}

IExpression* If::clone(){
    return new If(*this);
}
If::~If(){
    delete this->condition;
    delete this->consequence;
    delete this->alternative;
}
