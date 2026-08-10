#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    name = "anonymous";
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap default constructor called!" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap parameter constructor called!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap copy constructor called!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    if(this == &other)
        return *this;
    ClapTrap::operator=(other);
    std::cout << "FragTrap copy assignment operator called!" << std::endl;
    return *this;
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap destructor called!" << std::endl;
}

void FragTrap::highFivesGuys(void){
    std::cout << name << " sends high five request!" << std::endl;
}