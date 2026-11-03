#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    {
        std::cout << "\n--- Normal grade ---\n";
        Bureaucrat b("Alice", 42);
        std::cout << b << std::endl;
    }

    {
        std::cout << "\n--- Grade too high ---\n";
        try
        {
            Bureaucrat b("Bob", 0);
        }
        catch (const Bureaucrat::GradeTooHighException&)
        {
            std::cout << "Grade too high!" << std::endl;
        }
    }

    {
        std::cout << "\n--- Grade too low ---\n";
        try
        {
            Bureaucrat b("Charlie", 151);
        }
        catch (const Bureaucrat::GradeTooLowException&)
        {
            std::cout << "Grade too low!" << std::endl;
        }
    }

    {
        std::cout << "\n--- Increment grade ---\n";
        Bureaucrat b("Alice", 42);
        b.incrementGrade();
        std::cout << b << std::endl; // Grade 41
    }

    {
        std::cout << "\n--- Decrement grade ---\n";
        Bureaucrat b("Bob", 42);
        b.decrementGrade();
        std::cout << b << std::endl; // Grade 43
    }

    return 0;
}