#ifndef __FUNCTION_HPP__
#define __FUNCTION_HPP__

#include "../IExpression.hpp"
#include "../../Statements/LValueIdentifier/LValueIdentifier.hpp"
#include "../../Statements/BlockStatement/BlockStatement.hpp"
#include "../../Statements/ReturnStatement/ReturnStatement.hpp"

#include <vector>

class FunctionLiteral:public IExpression{
public:
    FunctionLiteral(Token token,BlockStatement* blockStatements,std::vector<LValueIdentifier*>args) ;
    FunctionLiteral(const FunctionLiteral& other);;
    virtual std::string getNodeType()override;
    virtual std::string getTokenLiteral()override;
    virtual std::string getValueLiteral()override;
    virtual std::string toString()override;
    virtual IExpression* clone()override;
    virtual ~FunctionLiteral();
private:
    Token token;
    std::vector<LValueIdentifier*> arguments;
    BlockStatement* blockStatements;
};


#endif
