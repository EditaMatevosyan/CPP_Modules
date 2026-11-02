#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("unknown"), _grade(150){
}

Bureaucrat::Bureaucrat(int grade): _name("unknown"){
    if(grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        _grade = grade;
}

std::string Bureaucrat::getName(){
    return _name;
}

int Bureaucrat::getGrade(){
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

std::ostream& operator<<(std::ostream& out, Bureaucrat& burbur)
{
    out << burbur.getName()
        << ", bureaucrat grade " << burbur.getGrade() << ".";
    return out;
}