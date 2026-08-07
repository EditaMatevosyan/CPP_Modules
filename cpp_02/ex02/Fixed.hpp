#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
    private:
        int rawValue;
        static const int bits = 8;
    public:
        Fixed();
        Fixed(const int num);
        Fixed(const float num);
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;

        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

        const Fixed operator+(const Fixed& other) const;
        const Fixed operator-(const Fixed& other) const;
        const Fixed operator/(const Fixed& other) const;
        const Fixed operator*(const Fixed& other) const; 
        
        Fixed& operator++();      
        const Fixed  operator++(int);   
        Fixed& operator--();      
        const Fixed  operator--(int);   

        static Fixed&       min(Fixed& a, Fixed& b);
        static Fixed const& min(Fixed const& a, Fixed const& b);
        static Fixed&       max(Fixed& a, Fixed& b);
        static Fixed const& max(Fixed const& a, Fixed const& b);
};

std::ostream& operator<<(std::ostream& out, const Fixed& f);

#endif