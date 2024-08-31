# pragma  once

#include "../IObject.hpp"
#include "../ObjectValues.enum.hpp"

class IntegerValue : public IObject{
public:
    IntegerValue(int value);
    std::string value() override;
    ObjectValues type() override;
private:
    int intValue;
};
