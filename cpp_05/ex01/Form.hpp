#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;
    
    public:
        Form();
        Form(const std::string& name, const int gradeToSign, const int gradeToExecute);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();
        
        std::string getName() const;
        bool isSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(const Bureaucrat& burbur);

        class GradeTooHighException : public std::exception {
        };
        class GradeTooLowException : public std::exception {
        };
};

std::ostream& operator<<(std::ostream& out, const Form& obj);


#endif