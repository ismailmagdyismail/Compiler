#include "../../../ObjectSystem/BooleanValue/BooleanValue.hpp"
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

IObject* Boolean::objectValue(){
    bool value = (token.tokenType == TokenType::TRUE) ? true : false;
    return new BooleanValue(value);
}

IExpression* Boolean::clone(){
    return new Boolean(this->token);
}
