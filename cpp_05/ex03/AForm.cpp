#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm() : _name("Unknown"),  _isSigned(false), _gradeToSign(150), _gradeToExecute(150){
    std::cout << "Default constructor of AForm called" << std::endl;
}

AForm::AForm (const std::string& name, const int gradeToSign, const int gradeToExecute) :\
             _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){
    std::cout << "Parameter constructor of AForm called" << std::endl;
    if(gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm (const AForm& other) : _name(other._name), _isSigned(other._isSigned), \
            _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
    std::cout << "Copy constructor of AForm called" << std::endl;
}

AForm& AForm::operator=(const AForm& other){
    std::cout << "Copy assignment of Bureaucrat operator called" << std::endl;
    if (this != &other)
        this->_isSigned = other.isSigned();
    return *this;
}

AForm::~AForm(){
    std::cout << "AForm destructor called" << std::endl;
}

std::string AForm::getName() const{
    return (_name);
}

bool AForm::isSigned() const{
    return(_isSigned);
}

int AForm::getGradeToSign() const{
    return(_gradeToSign);
}

int AForm::getGradeToExecute() const{
    return(_gradeToExecute);
}

std::ostream& operator<<(std::ostream& out, const AForm& obj){
    out << "AForm name: " << obj.getName()
        << ", Grade to sign: " << obj.getGradeToSign()
        << ", Grade to execute: " << obj.getGradeToExecute()
        << ", Signed: " << (obj.isSigned() ? "yes" : "no");
    return out;
}

void AForm::beSigned(const Bureaucrat& burbur){
    if(burbur.getGrade() > _gradeToSign)
        throw AForm::GradeTooLowException();
    else
        _isSigned = true;
}

void AForm::execute(const Bureaucrat& executor) const{
    if (executor.getGrade() > _gradeToExecute){
        throw AForm::GradeTooLowException();
    }
    else if (_isSigned == false){
        throw AForm::GradeUnsignedException();
    }
}