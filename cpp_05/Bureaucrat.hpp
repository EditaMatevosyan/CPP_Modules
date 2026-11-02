#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(int grade);

        class GradeTooHighException : public std::exception {
        };
        class GradeTooLowException : public std::exception {
        };
        
        std::string getName();
        int getGrade();
        void incrementGrade();
        void decrementGrade();
};

std::ostream& operator<<(std::ostream& out, Bureaucrat& burbur);


#endif