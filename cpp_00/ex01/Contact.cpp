#include <iostream>
#include "Contact.hpp"

Contact::Contact(){
}

bool Contact::isValidName(const std::string& s)
{
    if (s.empty())
        return false;
    for (size_t i = 0; i < s.length(); i++) {
        if (!std::isalpha(s[i]))
            return false;
    }
    return true;
}

bool Contact::isValidPhone(const std::string& s)
{
    if (s.empty())
        return false;
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    return true;
}

//setters
void Contact::setFirstName(){
    std::string input;
    std::cout << "Enter First Name: ";
    while(std::getline(std::cin, input)){
        if(isValidName(input)){
            firstName = input;
            return;
        }
        std::cout << "Name must contain only letters!" << std::endl;
        std::cout << "Enter First Name: ";
    }
}

void Contact::setLastName(){
    std::string input;
    std::cout << "Enter Last Name: ";
    while(std::getline(std::cin, input)){
        if(isValidName(input)){
            lastName = input;
            return;
        }
        std::cout << "Field must contain only letters!" << std::endl;
        std::cout << "Enter Last Name: ";
    }
}

void Contact::setNickname(){
    std::string input;
    std::cout << "Enter Nickname: ";
    while(std::getline(std::cin, input)){
        if(!input.empty()){
            nickname = input;
            return;
        }
        std::cout << "Field empty, try again!" << std::endl;
        std::cout << "Enter Nickname: ";
    }
}

void Contact::setPhoneNumber(){
    std::string input;
    std::cout << "Enter Phone Number: ";
    while(std::getline(std::cin, input)){
        if(isValidPhone(input)){
            phoneNumber = input;
            return;
        }
        std::cout << "Field must contain only digits!" << std::endl;
        std::cout << "Enter Phone Number: ";
    }
}

void Contact::setDarkestSecret(){
    std::string input;
    std::cout << "Enter Darkest Secret: ";
    while(std::getline(std::cin, input)){
        if(!input.empty()){
            darkestSecret = input;
            return;
        }
        std::cout << "Field empty, try again!" << std::endl;
        std::cout << "Enter Darkest Secret: ";
    }
}

void Contact::setAll(){
    if (std::cin.eof() == false)
        setFirstName();
    if (std::cin.eof() == false)
        setLastName();
    if (std::cin.eof() == false)
        setNickname();
    if (std::cin.eof() == false)
        setPhoneNumber();
    if (std::cin.eof() == false)
        setDarkestSecret();
}

//getters
std::string Contact::getFirstName() const{
    return(firstName);
}

std::string Contact::getLastName() const{
    return(lastName);
}

std::string Contact::getNickname() const{
    return(nickname);
}

std::string Contact::getPhoneNumber() const{
    return(phoneNumber);
}

std::string Contact::getDarkestSecret() const{
    return(darkestSecret);
}