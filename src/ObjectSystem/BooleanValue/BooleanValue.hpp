# pragma once

#include "../IObject.hpp"

class BooleanValue : public IObject{
public:
    BooleanValue(bool value);
    std::string value() override;
    ObjectValues type() override;

private:
    bool boolValue;
};
