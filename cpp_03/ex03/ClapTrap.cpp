#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("anonymous"), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "Default constructor called!" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "Parameter constructor called!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    name = other.name;
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
    std::cout << "Copy constructor called!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if(this == &other)
        return *this;
    name = other.name;
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
    std::cout << "Copy assignment operator called!" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap(){
    std::cout << "Destructor called!" << std::endl;
}

void ClapTrap::attack(const std::string& target){
    if (hitPoints <= 0 || energyPoints <= 0){
        std::cout << "ClapTrap " << name << " doesn't have enough hit points or energy points!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << name << " attacks " << target << " causing " << attackDamage << " points of damage!" << std::endl;
    energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount){
    if (hitPoints <= 0)
        return;
    if(amount >= hitPoints)
        hitPoints = 0;
    else
        hitPoints -= amount;
    std::cout << "ClapTrap " << name << " takes " << amount << " damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
    if (hitPoints <= 0 || energyPoints <= 0){
        std::cout << "ClapTrap " << name << " doesn't have enough hit points or energy points!" << std::endl;
        return;
    }
    hitPoints += amount;
    std::cout << "ClapTrap " << name << " repairs itself for " << amount << " hit points!" << std::endl;
    energyPoints--;
}