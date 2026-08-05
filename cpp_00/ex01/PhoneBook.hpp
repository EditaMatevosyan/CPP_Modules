#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include "Contact.hpp"

class PhoneBook {
    private:
        static const int maxContacts = 8;

        Contact contact[maxContacts];
        int nextIndex;
        int count;

        std::string truncate(const std::string& s) const;

    public:
        PhoneBook();

        void addContact(const Contact& newContact);
        void displayContact(int index) const;
        void displayContacts() const;
};

#endif