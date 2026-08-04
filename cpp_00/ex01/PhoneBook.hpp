#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iomanip>
#include <sstream>
#include "Contact.hpp"

class PhoneBook {
    private:
        Contact contact[8];
        int nextIndex;
        int count;
    
    public:
        PhoneBook();

        std::string truncate(const std::string& s) const;

        void addContact(const Contact& newContact);
        void displayContact(int index) const;
        void displayContacts() const;
};

#endif