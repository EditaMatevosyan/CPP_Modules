#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static AForm* createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

static AForm* createPardon(const std::string& target) {
    return new PresidentialPardonForm(target);
}

Intern::Intern() {
    std::cout << "Default constructor of Intern called" << std::endl;
}

Intern::Intern(const Intern& other){
    (void)other;
    std::cout << "Copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other){
    (void)other;
    std::cout << "Copy assignment of Intern operator called" << std::endl;
    return *this;
}

Intern::~Intern(){
    std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::makeForm(const std::string& form,
                        const std::string& target) {

    const std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (*creators[3])(const std::string&) = {
        createShrubbery,
        createRobotomy,
        createPardon
    };

    for (int i = 0; i < 3; i++) {
        if (form == names[i]) {
            AForm* result = creators[i](target);
            std::cout << "Intern creates " << form << std::endl;
            return result;
        }
    }

    std::cout << "Intern cannot create unknown form: "
              << form << std::endl;
    return NULL;
}
