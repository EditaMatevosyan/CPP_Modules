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
        }else if(command == "SEARCH"){
            phoneBook.displayContacts();
            std::cout << "Enter index: ";
            std::string input; 
            std::getline(std::cin, input);
            std::istringstream iss(input);
            int index = -1;
            iss >> index;
            phoneBook.displayContact(index);
        }else if(command == "EXIT"){
            break;
        }
        std::cout << "Enter Command(ADD/SEARCH/EXIT): ";
    }

}
