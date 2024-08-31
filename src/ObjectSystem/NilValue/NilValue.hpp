#include "../IObject.hpp"

class NilValue : public IObject{
public:
    std::string value() override;
    ObjectValues type() override;
};
