#ifndef __IF_HPP__
#define __IF_HPP__

#include "../IExpression.hpp"
#include "../../Statements/BlockStatement/BlockStatement.hpp"
#include "../../../tokens/Token.hpp"

class If: public IExpression{
public:
    If(IExpression* condition ,BlockStatement* consequence);
    If(const If& other);
    void setCondition(IExpression* expression);
    void setConsequence(BlockStatement* consequence);
    void setAlternative(BlockStatement* alternative);
    std::string toString() override;
    std::string getTokenLiteral() override;
    std::string getNodeType() override;
    std::string getValueLiteral() override;
    IObject* objectValue() override;
    virtual IExpression* clone() override;
    virtual ~If();
private:
    Token token;
    IExpression* condition;
    BlockStatement* consequence;
    BlockStatement* alternative;
};

#endif
