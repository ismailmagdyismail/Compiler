#ifndef __BLOCKSTATEMENT_HPP__
#define __BLOCKSTATEMENT_HPP__

#include "../IStatement.hpp"
#include "../../../tokens/Token.hpp"
#include <vector>

class BlockStatement:public IStatement{
public:
    BlockStatement() = default;
    BlockStatement(const BlockStatement& other);
    void addStatement(IStatement* statement);
    void setToken(Token token);
    virtual std::string toString() override;
    virtual std::string getTokenLiteral() override;
    virtual std::string getNodeType() override;
    virtual IStatement* clone() override;
    BlockStatement* getCopy();
    virtual ~BlockStatement();
private:
    Token token;
    std::vector<IStatement*>statements;
};


#endif
