#include "./LValueIdentifier.hpp"
#include "../../../ObjectSystem/NilValue/NilValue.hpp"

#include <iostream>

LValueIdentifier::LValueIdentifier(const LValueIdentifier &other) {
  this->token = other.token;
}

LValueIdentifier::LValueIdentifier(Token token) { this->token = token; }

LValueIdentifier &LValueIdentifier::operator=(const LValueIdentifier &other) {
  this->token = other.token;
  return *this;
}

LValueIdentifier* LValueIdentifier::getCopy(){
    return new LValueIdentifier(*this);
}

std::string LValueIdentifier::getTokenLiteral() {
  return this->token.literalValue;
}

std::string LValueIdentifier::getNodeType() { return "IdentifierNode"; }

std::string LValueIdentifier::toString() { return this->getTokenLiteral(); }

IObject* LValueIdentifier::objectValue(){
    return new NilValue();
}

IStatement *LValueIdentifier::clone() {
  return new LValueIdentifier(this->token);
}

LValueIdentifier::~LValueIdentifier() {}
