#include "Zombie.hpp"

Zombie::Zombie() : name("Unnamed Zombie") {}

void Zombie::setName(const std::string& new_name){
    name = new_name;
}

void Zombie::announce() {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie() {
    std::cout << name << " is destroyed" << std::endl;
}