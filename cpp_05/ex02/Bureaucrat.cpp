#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(): _name("unknown"), _grade(150){
    std::cout << "Default constructor of Bureaucrat called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name), _grade(grade){
    std::cout << "Parameter constructor of Bureaucrat called" << std::endl;
    if(grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name), _grade(other._grade){
    std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
    std::cout << "Copy assignment of Bureaucrat operator called" << std::endl;
    if (this != &other)
        this->_grade = other.getGrade();
    return *this;
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat destructor called" << std::endl;
}

const std::string Bureaucrat::getName() const{
    return _name;
}

int Bureaucrat::getGrade() const{
    return _grade;
}

void Bureaucrat::incrementGrade(){
    if(_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    _grade -= 1;
}

void Bureaucrat::decrementGrade(){
    if(_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade += 1;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& burbur)
{
    out << burbur.getName()
        << ", bureaucrat grade " << burbur.getGrade() << ".";
    return out;
}

void Bureaucrat::signForm(AForm& form){
    try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (AForm::GradeTooLowException& e) {
		std::cout << this->getName() << " couldn't sign " << form.getName() \
                    << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm& form) const{
    try {
        form.execute(*this);
        std::cout << getName() << " executed "
                  << form.getName() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << getName() << " couldn't execute "
                  << form.getName()
                  << " because " << e.what() << std::endl;
    }
}