#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal"){
    std::cout << "WrongAnimal default constructor called!" << std::endl;
}

WrongAnimal::WrongAnimal (const WrongAnimal& other) : type(other.type) {
    std::cout << "WrongAnimal copy constructor called!" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other){
    if(this == &other)
        return *this;
    std::cout << "WrongAnimal copy assignement operator called!" << std::endl;
    this->type = other.type;
    return *this;
}

WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal destructor called!" << std::endl;
}

std::string WrongAnimal::getType() const{
    return type;
}

void WrongAnimal::makeSound() const{
    std::cout << "WrongAnimal makes sound!" << std::endl;
}