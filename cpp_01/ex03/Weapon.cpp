#include "Weapon.hpp"

//     const std::string& getType() const; 1st const does not allow to change the type, 2nd const says that getType cannot make changes in the class

const std::string& Weapon::getType() const{
    return type;
}

void Weapon::setType(std::string newType){
    type = newType;
}

Weapon::Weapon(std::string type) : type(type){
}
