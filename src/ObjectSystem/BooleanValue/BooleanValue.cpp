#include "BooleanValue.hpp"
#include <string>

BooleanValue::BooleanValue(bool value){
    boolValue = value;
}

std::string BooleanValue::value(){
    return boolValue ? "true" : "false";
}

ObjectValues BooleanValue::type(){
    return ObjectValues::BOOLEAN;
}
