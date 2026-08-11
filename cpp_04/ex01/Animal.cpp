#include "Animal.hpp"

Animal::Animal() : type("Animal"){
    std::cout << "Animal default constructor called!" << std::endl;
}

Animal::Animal (const Animal& other) : type(other.type) {
    std::cout << "Animal copy constructor called!" << std::endl;
}

Animal& Animal::operator=(const Animal& other){
    if(this == &other)
        return *this;
    std::cout << "Animal copy assignement operator called!" << std::endl;
    this->type = other.type;
    return *this;
}

Animal::~Animal(){
    std::cout << "Animal destructor called!" << std::endl;
}

std::string Animal::getType() const{
    return type;
}

void Animal::makeSound() const{
    std::cout << "Animal makes sound!" << std::endl;
}