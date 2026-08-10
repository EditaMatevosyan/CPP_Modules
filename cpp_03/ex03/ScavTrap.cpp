#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    name = "anonymous";
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap default constructor called!" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap parameter constructor called!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap copy constructor called!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if(this == &other)
        return *this;
    ClapTrap::operator=(other);
    std::cout << "ScavTrap copy assignment operator called!" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap destructor called!" << std::endl;
}

void ScavTrap::attack(const std::string& target){
    if (hitPoints <= 0 || energyPoints <= 0){
        std::cout << "ScavTrap " << name << " doesn't have enough hit points or energy points!" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << name << " attacks " << target << " causing " << attackDamage << " points of damage!" << std::endl;
    energyPoints--;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode!" << std::endl;
}