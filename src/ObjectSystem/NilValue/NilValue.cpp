#include "NilValue.hpp"

std::string NilValue::value(){
    return "NIL";
}

ObjectValues NilValue::type(){
    return ObjectValues::NIL;
}
