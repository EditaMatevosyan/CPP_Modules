#include "Dog.hpp"

Dog::Dog(){
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog default constructor called!" << std::endl;
}

Dog::Dog (const Dog& other) : Animal(other), brain(new Brain(*other.brain)){
    std::cout << "Dog copy constructor called!" << std::endl;
}

Dog& Dog::operator=(const Dog& other){
    if(this == &other)
        return *this;
    std::cout << "Dog copy assignement operator called!" << std::endl;
    Animal::operator=(other);
    delete brain;
    brain = new Brain(*other.brain);
    return *this;
}

Dog::~Dog(){
    delete brain;
    std::cout << "Dog destructor called!" << std::endl;
}

void Dog::makeSound() const{
    std::cout << "barf barf" << std::endl;
}

Brain* Dog::getBrain() const{
    return brain;
}