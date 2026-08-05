#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : nextIndex(0), count(0){

}

std::string PhoneBook::truncate(const std::string& s) const{
    if (s.length() > 10)
        return s.substr(0, 9) + ".";
    return s;
}
 
void PhoneBook::addContact(const Contact& newContact){
    contact[nextIndex] = newContact;
    nextIndex = (nextIndex + 1) % maxContacts;
    if(count < maxContacts){
        count++;
    }
}

void PhoneBook::displayContact(int index) const {
    if(index < 0 || index >= count){
        std::cout << "Invalid index!" << std::endl;
        return;
    }
    std::cout << "First name: " << contact[index].getFirstName() << std::endl;
    std::cout << "Last name: " << contact[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contact[index].getNickname() << std::endl;
    std::cout << "Phone number: " << contact[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contact[index].getDarkestSecret() << std::endl;
}

void PhoneBook::displayContacts() const{
    std::cout << std::right
        << std::setw(10) << "Index" << "|" 
        << std::setw(10) << "First Name" << "|"
        << std::setw(10) << "Last Name" << "|"
        << std::setw(10) << "Nickname" << "|"
        << std::endl;
    for(int i = 0; i < count; i++){
        std::cout << std::right
                << std::setw(10) << i << "|" 
                << std::setw(10) << truncate(contact[i].getFirstName()) << "|"
                << std::setw(10) << truncate(contact[i].getLastName()) << "|"
                << std::setw(10) << truncate(contact[i].getNickname()) << "|"
                << std::endl;
    }
}

