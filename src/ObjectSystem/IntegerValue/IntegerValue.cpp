#include "IntegerValue.hpp"
#include <string>


IntegerValue::IntegerValue(int value){
    intValue = value;
}

std::string IntegerValue::value(){
    return std::to_string(intValue);
}

ObjectValues IntegerValue::type(){
    return ObjectValues::INTEGER;
}
