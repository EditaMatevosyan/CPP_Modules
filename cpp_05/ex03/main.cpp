
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(NULL));

    Intern intern;
    Bureaucrat boss("Boss", 1);

    // TEST 1: Robotomy Request
    std::cout << "\n===== TEST 1: ROBOTOMY =====\n";
    {
        AForm* form = intern.makeForm("robotomy request", "Bender");

        if (form != NULL) {
            std::cout << *form << std::endl;
            boss.signForm(*form);
            boss.executeForm(*form);
            delete form;
        }
    }

    // TEST 2: Shrubbery Creation
    std::cout << "\n===== TEST 2: SHRUBBERY =====\n";
    {
        AForm* form = intern.makeForm("shrubbery creation", "garden");

        if (form != NULL) {
            boss.signForm(*form);
            boss.executeForm(*form);
            delete form;
        }
    }

    // TEST 3: Presidential Pardon
    std::cout << "\n===== TEST 3: PRESIDENTIAL PARDON =====\n";
    {
        AForm* form = intern.makeForm("presidential pardon", "Arthur");

        if (form != NULL) {
            boss.signForm(*form);
            boss.executeForm(*form);
            delete form;
        }
    }

    // TEST 4: Unknown Form
    std::cout << "\n===== TEST 4: UNKNOWN FORM =====\n";
    {
        AForm* form = intern.makeForm("unknown form", "Nobody");

        if (form == NULL)
            std::cout << "Correctly handled unknown form."
                      << std::endl;
        else
            delete form;
    }

    // TEST 5: Execute unsigned form
    std::cout << "\n===== TEST 5: UNSIGNED FORM =====\n";
    {
        AForm* form = intern.makeForm("robotomy request", "Robot");

        if (form != NULL) {
            boss.executeForm(*form);
            boss.signForm(*form);
            boss.executeForm(*form);
            delete form;
        }
    }

    // TEST 6: Insufficient grade
    std::cout << "\n===== TEST 6: INSUFFICIENT GRADE =====\n";
    {
        Bureaucrat low("LowRank", 150);
        AForm* form = intern.makeForm("presidential pardon", "Ford");

        if (form != NULL) {
            low.signForm(*form);
            boss.signForm(*form);
            low.executeForm(*form);
            boss.executeForm(*form);
            delete form;
        }
    }

    // TEST 7: Multiple independent forms
    std::cout << "\n===== TEST 7: MULTIPLE FORMS =====\n";
    {
        AForm* first = intern.makeForm("robotomy request", "Bender");
        AForm* second = intern.makeForm("robotomy request", "Marvin");

        if (first != NULL && second != NULL) {
            boss.signForm(*first);
            std::cout << "First: " << *first << std::endl;
            std::cout << "Second: " << *second << std::endl;
        }

        delete first;
        delete second;
    }

    std::cout << "\n===== END OF TESTS =====\n";
    return 0;
}
