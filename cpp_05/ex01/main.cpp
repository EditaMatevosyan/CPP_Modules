#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <exception>

int main()
{
    {
        std::cout << "\n--- Successful signing ---\n";
        try
        {
            Bureaucrat b("Alice", 30);
            Form form("Holiday request", 50, 25);

            std::cout << "Before: " << form << std::endl;
            b.signForm(form);
            std::cout << "After:  " << form << std::endl;
            // Expected: signed
        }
        catch (const std::exception& e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }

    {
        std::cout << "\n--- Insufficient authority ---\n";
        try
        {
            Bureaucrat b("Bob", 80);
            Form form("Holiday request", 50, 25);

            b.signForm(form); // Catches signing failure internally
            std::cout << form << std::endl;
            // Expected: still unsigned
        }
        catch (const std::exception& e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }

    {
        std::cout << "\n--- Exact required grade ---\n";
        try
        {
            Bureaucrat b("Charlie", 50);
            Form form("Holiday request", 50, 25);

            b.signForm(form);
            std::cout << form << std::endl;
            // Expected: signed
        }
        catch (const std::exception& e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }

    {
        std::cout << "\n--- Direct beSigned failure ---\n";
        try
        {
            Bureaucrat b("Bob", 80);
            Form form("Holiday request", 50, 25);

            form.beSigned(b); // Exception reaches this scope's catch
        }
        catch (const Form::GradeTooLowException& e)
        {
            std::cout << "Signing failed: " << e.what() << std::endl;
        }
    }

    {
        std::cout << "\n--- Signing grade too high ---\n";
        try
        {
            Form form("Invalid", 0, 25);
        }
        catch (const Form::GradeTooHighException& e)
        {
            std::cout << "Invalid form: " << e.what() << std::endl;
        }
    }

    {
        std::cout << "\n--- Signing grade too low ---\n";
        try
        {
            Form form("Invalid", 151, 25);
        }
        catch (const Form::GradeTooLowException& e)
        {
            std::cout << "Invalid form: " << e.what() << std::endl;
        }
    }

    {
        std::cout << "\n--- Execution grade too high ---\n";
        try
        {
            Form form("Invalid", 50, 0);
        }
        catch (const Form::GradeTooHighException& e)
        {
            std::cout << "Invalid form: " << e.what() << std::endl;
        }
    }

    {
        std::cout << "\n--- Execution grade too low ---\n";
        try
        {
            Form form("Invalid", 50, 151);
        }
        catch (const Form::GradeTooLowException& e)
        {
            std::cout << "Invalid form: " << e.what() << std::endl;
        }
    }

    return 0;
}