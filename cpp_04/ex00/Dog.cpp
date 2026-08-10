#include "Dog.hpp"

Dog::Dog(){
    this->type = "Dog";
    std::cout << "Dog default constructor called!" << std::endl;
}

Dog::Dog (const Dog& other) : Animal(other){
    std::cout << "Dog copy constructor called!" << std::endl;
}

Dog& Dog::operator=(const Dog& other){
    if(this == &other)
        return *this;
    std::cout << "Dog copy assignement operator called!" << std::endl;
    Animal::operator=(other);
    return *this;
}

Dog::~Dog(){
    std::cout << "Dog destructor called!" << std::endl;
}

void Dog::makeSound() const{
    std::cout << "barf barf" << std::endl;
}