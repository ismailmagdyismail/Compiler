#include "./Boolean.hpp"

Boolean::Boolean(Token token){
    this->token = token;
}

std::string Boolean::toString(){
    return this->token.literalValue;
}

std::string Boolean::getNodeType(){
    return "Boolean Node";
}

std::string Boolean::getTokenLiteral(){
    return this->token.literalValue;
}

std::string Boolean::getValueLiteral(){
    return this->token.literalValue;
}

IExpression* Boolean::clone(){
    return new Boolean(this->token);
}
