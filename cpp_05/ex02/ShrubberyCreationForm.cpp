#include "ShrubberyCreationForm.hpp"

const std::string ShrubberyCreationForm::shrubbery =
    "       /\\\n"
    "      /**\\\n"
    "     /****\\\n"
    "    /******\\\n"
    "       ||\n"
    "       ||\n";

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("Unknown") {
	std::cout << "Default constructor of ShrubberyCreationForm called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {
	std::cout << "Constructor of ShrubberyCreationForm with parameters called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target) {
	std::cout << "Copy constructor of ShrubberyCreationForm called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	std::cout << "Copy assignment of ShrubberyCreationForm operator called" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
		this->target = other.target;
	}
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {

    AForm::execute(executor);

    const std::string filename = target + "_shrubbery";
    std::ofstream out(filename.c_str());

    if (!out.is_open())
        throw std::runtime_error("cannot create shrubbery file");

    out << shrubbery;

    out.close();

    if (!out)
        throw std::runtime_error("failed to write shrubbery file");
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Destructor of ShrubberyCreationForm called" << std::endl;
}