# pragma once

#include "ObjectValues.enum.hpp"
#include <iostream>

class IObject{
public:
    virtual ObjectValues type() = 0 ;
    virtual std::string value() = 0 ;
    virtual ~IObject() = default ;
};
