#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : _name("Unknown"), _isSigned(false),  _gradeToSign(150), _gradeToExecute(150){
    std::cout << "Default constructor of Form called" << std::endl;
}

Form::Form (const std::string& name, const int gradeToSign, const int gradeToExecute) :\
             _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){
    std::cout << "Parameter constructor of Form called" << std::endl;
    if(gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form (const Form& other) : _name(other._name), _isSigned(other._isSigned), \
            _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
    std::cout << "Copy constructor of Form called" << std::endl;
}

Form& Form::operator=(const Form& other){
    std::cout << "Copy assignment of Bureaucrat operator called" << std::endl;
    if (this != &other)
        this->_isSigned = other.isSigned();
    return *this;
}

Form::~Form(){
    std::cout << "Form destructor called" << std::endl;
}

std::string Form::getName() const{
    return (_name);
}

bool Form::isSigned() const{
    return(_isSigned);
}

int Form::getGradeToSign() const{
    return(_gradeToSign);
}

int Form::getGradeToExecute() const{
    return(_gradeToExecute);
}

std::ostream& operator<<(std::ostream& out, const Form& obj){
    out << "Form name: " << obj.getName()
        << ", Grade to sign: " << obj.getGradeToSign()
        << ", Grade to execute: " << obj.getGradeToExecute()
        << ", Signed: " << (obj.isSigned() ? "yes" : "no");
    return out;
}

void Form::beSigned(const Bureaucrat& burbur){
    if(burbur.getGrade() > _gradeToSign)
        throw Form::GradeTooLowException();
    else
        _isSigned = true;
}
