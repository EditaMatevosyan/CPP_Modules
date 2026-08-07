#include "Fixed.hpp"

Fixed::Fixed () : rawValue(0) { 
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : rawValue(other.rawValue) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other){
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &other)
        this->rawValue = other.rawValue;
    return *this;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed (const int num) : rawValue(num << bits){
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed (const float num) : rawValue(roundf(num  * (1 << bits))){
    std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat( void ) const{
    return rawValue/(float)(1 << bits);
}

int Fixed::toInt( void ) const{
    return rawValue >> bits;
}

int Fixed::getRawBits( void ) const{
    std::cout << "getRawBits member function called" << std::endl;
    return(rawValue);
}

void Fixed::setRawBits( int const raw ){
    std::cout << "setRawBits member function called" << std::endl;
    rawValue = raw;
}

std::ostream& operator<<(std::ostream& out, const Fixed& f){
    out << f.toFloat();
    return out;
}