#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;
    
    public:
        AForm();
        AForm(const std::string& name, const int gradeToSign, const int gradeToExecute);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();
        
        std::string getName() const;
        bool isSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(const Bureaucrat& burbur);
        virtual void  execute(Bureaucrat const & executor) const = 0;

        class GradeTooHighException : public std::exception {
        };
        class GradeTooLowException : public std::exception {
        };
        class GradeUnsignedException : public std::exception {
        };
};

std::ostream& operator<<(std::ostream& out, const AForm& obj);


#endif