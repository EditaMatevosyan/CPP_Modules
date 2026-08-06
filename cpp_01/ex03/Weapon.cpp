#include "Weapon.hpp"

const std::string& Weapon::getType() const{
    return type;
}

void Weapon::setType(std::string newType){
    type = newType;
}

Weapon::Weapon(std::string type) : type(type){
}
