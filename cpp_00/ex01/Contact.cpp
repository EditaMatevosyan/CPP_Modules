#include "Contact.hpp"

Contact::Contact(){
}

void Contact::setAll(){
    setFirstName();
    if(std::cin.eof())
        return;
    setLastName();
    if(std::cin.eof())
        return;
    setNickname();
    if(std::cin.eof())
        return;
    setPhoneNumber();
    if(std::cin.eof())
        return;
    setDarkestSecret();
    if(std::cin.eof())
        return;
}

//setters
void Contact::setFirstName(){
    std::string input;
    std::cout << "Enter First Name: ";
    while(std::getline(std::cin, input)){
        if(!input.empty()){
            firstName = input;
            return;
        }
        std::cout << "Field empty, try again!" << std::endl;
            std::cout << "Enter First Name: ";
    }
}

void Contact::setLastName(){
    std::string input;
    std::cout << "Enter Last Name: ";
    while(std::getline(std::cin, input)){
        if(!input.empty()){
            lastName = input;
            return;
        }
        std::cout << "Field empty, try again!" << std::endl;
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
        if(!input.empty()){
            phoneNumber = input;
            return;
        }
        std::cout << "Field empty, try again!" << std::endl;
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