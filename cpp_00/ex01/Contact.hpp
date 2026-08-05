#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <cctype>

class Contact {
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;

        static bool isValidName(const std::string& s);
        static bool isValidPhone(const std::string& s);

    public:
        Contact();

        bool setAll();
        void setFirstName();
        void setLastName();
        void setNickname();
        void setPhoneNumber();
        void setDarkestSecret();

        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickname() const;
        std::string getPhoneNumber() const;
        std::string getDarkestSecret() const;
};

#endif