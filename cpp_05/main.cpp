#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

int main()
{
    {
        std::cout << "\n--- Default constructor ---\n";
        Bureaucrat b;
        std::cout << b << std::endl;
        // Expected: unknown, grade 150
    }

    {
        std::cout << "\n--- Valid middle grade ---\n";
        Bureaucrat b(75);
        std::cout << b << std::endl;
        // Expected: grade 75
    }

    {
        std::cout << "\n--- Highest valid grade ---\n";
        Bureaucrat b(1);
        std::cout << b << std::endl;
        // Expected: grade 1
    }

    {
        std::cout << "\n--- Lowest valid grade ---\n";
        Bureaucrat b(150);
        std::cout << b << std::endl;
        // Expected: grade 150
    }

    {
        std::cout << "\n--- Invalid grade: 0 ---\n";
        try
        {
            Bureaucrat b(0);
            std::cout << "ERROR: construction succeeded\n";
        }
        catch (const Bureaucrat::GradeTooHighException&)
        {
            std::cout << "Caught: grade too high\n";
        }
    }

    {
        std::cout << "\n--- Invalid negative grade ---\n";
        try
        {
            Bureaucrat b(-10);
            std::cout << "ERROR: construction succeeded\n";
        }
        catch (const Bureaucrat::GradeTooHighException&)
        {
            std::cout << "Caught: grade too high\n";
        }
    }

    {
        std::cout << "\n--- Invalid grade: 151 ---\n";
        try
        {
            Bureaucrat b(151);
            std::cout << "ERROR: construction succeeded\n";
        }
        catch (const Bureaucrat::GradeTooLowException&)
        {
            std::cout << "Caught: grade too low\n";
        }
    }

    {
        std::cout << "\n--- Increment a valid grade ---\n";
        Bureaucrat b(75);
        b.incrementGrade();
        std::cout << b << std::endl;
        // Expected: grade 74 (promotion)
    }

    {
        std::cout << "\n--- Decrement a valid grade ---\n";
        Bureaucrat b(75);
        b.decrementGrade();
        std::cout << b << std::endl;
        // Expected: grade 76 (demotion)
    }

    {
        std::cout << "\n--- Increment to the highest grade ---\n";
        Bureaucrat b(2);
        b.incrementGrade();
        std::cout << b << std::endl;
        // Expected: grade 1
    }

    {
        std::cout << "\n--- Decrement to the lowest grade ---\n";
        Bureaucrat b(149);
        b.decrementGrade();
        std::cout << b << std::endl;
        // Expected: grade 150
    }

    {
        std::cout << "\n--- Increment beyond grade 1 ---\n";
        Bureaucrat b(1);

        try
        {
            b.incrementGrade();
            std::cout << "ERROR: increment succeeded\n";
        }
        catch (const Bureaucrat::GradeTooHighException&)
        {
            std::cout << "Caught: grade too high\n";
        }

        std::cout << "After failed increment: " << b << std::endl;
        // Expected: still grade 1

        b.decrementGrade();
        std::cout << "After valid decrement: " << b << std::endl;
        // Expected: grade 2; object remains usable
    }

    {
        std::cout << "\n--- Decrement beyond grade 150 ---\n";
        Bureaucrat b(150);

        try
        {
            b.decrementGrade();
            std::cout << "ERROR: decrement succeeded\n";
        }
        catch (const Bureaucrat::GradeTooLowException&)
        {
            std::cout << "Caught: grade too low\n";
        }

        std::cout << "After failed decrement: " << b << std::endl;
        // Expected: still grade 150

        b.incrementGrade();
        std::cout << "After valid increment: " << b << std::endl;
        // Expected: grade 149; object remains usable
    }

    {
        std::cout << "\n--- Catch through std::exception ---\n";
        try
        {
            Bureaucrat b(151);
        }
        catch (const std::exception& e)
        {
            std::cout << "Caught through base class: "
                      << e.what() << std::endl;
        }
        // Your exceptions currently inherit the default what() message.
    }

    {
        std::cout << "\n--- Getters and stream chaining ---\n";
        Bureaucrat b(42);

        std::cout << "Name: " << b.getName() << std::endl;
        std::cout << "Grade: " << b.getGrade() << std::endl;
        std::cout << "Object: " << b << " [end]" << std::endl;
    }

    return 0;
}