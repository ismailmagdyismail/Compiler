#ifndef __BOOLEAN_HPP__
#define __BOOLEAN_HPP__

#include "../IExpression.hpp"
#include "../../../tokens/Token.hpp"

class Boolean: public IExpression{
public:
    // Should make tokens maybe into classes not enums , to enforce right tokens passed to each node
     Boolean(Token token);
     virtual std::string toString() override;
     virtual std::string getValueLiteral() override;
     virtual std::string getNodeType() override;
     virtual std::string getTokenLiteral() override;
     virtual IObject* objectValue() override;
     virtual IExpression* clone() override;

private:
    Token token ;
};

#endif
