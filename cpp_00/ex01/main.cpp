#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int main(){
    PhoneBook phoneBook;
    std::string command;

    std::cout << "Enter Command(ADD/SEARCH/EXIT): ";
    while (std::getline(std::cin, command)){
        if(command == "ADD"){
            Contact newContact;
            newContact.setAll();
            phoneBook.addContact(newContact);
        } else if (command == "SEARCH") {
            phoneBook.displayContacts();
            std::cout << "Enter index: ";
            std::string input;
            std::getline(std::cin, input);

            if (input.length() != 1 || input[0] < '0' || input[0] > '9')
                std::cout << "Invalid input!" << std::endl;
            else
                phoneBook.displayContact(input[0] - '0');
        } else if(command == "EXIT"){
            break;
        }
        std::cout << "Enter Command(ADD/SEARCH/EXIT): ";
    }
    return 0;
}
