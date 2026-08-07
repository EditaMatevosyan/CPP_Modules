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

bool Fixed::operator>(const Fixed& other) const{
    return (this->rawValue > other.rawValue);
}

bool Fixed::operator<(const Fixed& other) const{
    return (this->rawValue < other.rawValue);
}

bool Fixed::operator>=(const Fixed& other) const{
    return (this->rawValue >= other.rawValue);
}

bool Fixed::operator<=(const Fixed& other) const{
    return (this->rawValue <= other.rawValue);
}

bool Fixed::operator==(const Fixed& other) const{
    return (this->rawValue == other.rawValue);
}

bool Fixed::operator!=(const Fixed& other) const{
    return (this->rawValue != other.rawValue);
}

const Fixed Fixed::operator+(const Fixed& other) const{
    return (this->toFloat() + other.toFloat());
}

const Fixed Fixed::operator-(const Fixed& other) const{
    return (this->toFloat() - other.toFloat());
}

const Fixed Fixed::operator*(const Fixed& other) const{
    return (this->toFloat() * other.toFloat());
}

const Fixed Fixed::operator/(const Fixed& other) const{
    return (this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++(){
    ++this->rawValue;
    return *this;
}

Fixed& Fixed::operator--(){
    --this->rawValue;
    return *this;
}

const Fixed  Fixed::operator++(int){
    Fixed temp(*this);
    ++this->rawValue;
    return temp;
}

const Fixed  Fixed::operator--(int){
    Fixed temp(*this);
    --this->rawValue;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return ((a < b) ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return ((a > b) ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return ((a < b) ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return ((a > b) ? a : b);
}