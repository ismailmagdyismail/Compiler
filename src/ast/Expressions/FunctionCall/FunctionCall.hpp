#ifndef __FUNCTION_CALL_HPP__
#define  __FUNCTION_CALL_HPP__

#include "../IExpression.hpp"
#include "../../../tokens/Token.hpp"
#include <vector>

class FunctionCall:public IExpression{
public:
    FunctionCall(Token token,IExpression* function,std::vector<IExpression*> arguments);
    FunctionCall(const FunctionCall& other);
    virtual std::string getNodeType() override;
    virtual std::string getTokenLiteral() override;
    virtual std::string getValueLiteral() override;
    virtual std::string toString() override;
    virtual IObject* objectValue() override;
    virtual IExpression* clone() override;
    virtual ~FunctionCall();
private :
    std::vector<IExpression*>arguments;
    IExpression* function ;
    Token token ;
};


#endif
