
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(NULL));

    // TEST 1: ShrubberyCreationForm
    std::cout << "\n===== TEST 1: SHRUBBERY =====\n";
    {
        Bureaucrat signer("Alice", 145);
        Bureaucrat executor("Bob", 137);
        Bureaucrat low("Charlie", 138);

        ShrubberyCreationForm form("garden");

        std::cout << form << std::endl;

        // Cannot execute unsigned form
        executor.executeForm(form);

        // Sign the form
        signer.signForm(form);

        // Grade too low to execute
        low.executeForm(form);

        // Successful execution
        executor.executeForm(form);
    }

    // TEST 2: RobotomyRequestForm
    std::cout << "\n===== TEST 2: ROBOTOMY =====\n";
    {
        Bureaucrat signer("David", 72);
        Bureaucrat executor("Emma", 45);

        RobotomyRequestForm form("Bender");

        signer.signForm(form);

        // Test 50% probability several times
        for (int i = 0; i < 5; i++) {
            executor.executeForm(form);
        }
    }

    // TEST 3: PresidentialPardonForm
    std::cout << "\n===== TEST 3: PRESIDENTIAL PARDON =====\n";
    {
        Bureaucrat signer("Frank", 25);
        Bureaucrat executor("Grace", 5);

        PresidentialPardonForm form("Arthur");

        signer.signForm(form);

        // Signer has insufficient execution grade
        signer.executeForm(form);

        // Successful execution
        executor.executeForm(form);
    }

    // TEST 4: Signing failure
    std::cout << "\n===== TEST 4: SIGNING FAILURE =====\n";
    {
        Bureaucrat low("Henry", 150);
        ShrubberyCreationForm form("forest");

        // Grade 150 cannot sign (requires 145)
        low.signForm(form);

        std::cout << form << std::endl;
    }

    // TEST 5: Polymorphism
    std::cout << "\n===== TEST 5: POLYMORPHISM =====\n";
    {
        Bureaucrat boss("Boss", 1);
        RobotomyRequestForm robot("Robot");

        AForm& form = robot;

        boss.signForm(form);
        boss.executeForm(form);
    }

    // TEST 6: Invalid bureaucrat grade
    std::cout << "\n===== TEST 6: EXCEPTIONS =====\n";
    {
        try {
            Bureaucrat invalid("Invalid", 0);
        }
        catch (const std::exception& e) {
            std::cout << "Exception caught: "
                      << e.what() << std::endl;
        }
    }

    return 0;
}
