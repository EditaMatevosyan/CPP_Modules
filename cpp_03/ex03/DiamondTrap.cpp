#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap() {
    this->name = "anonymous";
    ClapTrap::name = this->name + "_clap_name";
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 30;
    std::cout << "DiamondTrap default constructor called!" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name){
    this->name = name;
    ClapTrap::name = this->name + "_clap_name";
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 30;
    std::cout << "DiamondTrap parameter constructor called!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name) {
    std::cout << "DiamondTrap copy constructor called!" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if(this == &other)
        return *this;
    this->name = other.name;
    ClapTrap::operator=(other);
    std::cout << "DiamondTrap copy assignment operator called!" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap(){
    std::cout << "DiamondTrap destructor called!" << std::endl;
}

void DiamondTrap::whoAmI(){
    std::cout << "My name is " << this->name << " and my ClapTrap name is " << this->ClapTrap::name << std::endl;
}

void DiamondTrap::attack(const std::string& target){
    ScavTrap::attack(target);
} 