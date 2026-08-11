#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "=== Animal is now abstract ===" << std::endl;
    {
        // Animal a;                  // error: cannot declare variable of abstract type
        // Animal* bad = new Animal(); // error: cannot allocate an object of abstract type

        std::cout << "(Animal a; and new Animal(); are commented out on purpose --"
                   << " uncomment to prove they fail to compile)" << std::endl;
    }

    std::cout << std::endl << "=== Everything else still works through base pointers ===" << std::endl;
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        j->makeSound();
        i->makeSound();

        delete j; 
        delete i;
    }

    std::cout << std::endl << "=== Array of Animals, half Dog half Cat ===" << std::endl;
    {
        Animal* animals[6];

        for (int k = 0; k < 3; k++)
            animals[k] = new Dog();
        for (int k = 3; k < 6; k++)
            animals[k] = new Cat();

        for (int k = 0; k < 6; k++)
            animals[k]->makeSound();

        for (int k = 0; k < 6; k++)
            delete animals[k];
    }

    std::cout << std::endl << "=== Deep copy test: Dog (copy constructor) ===" << std::endl;
    {
        Dog original;
        original.getBrain()->setIdea(0, "sniff everything");

        Dog copy(original);

        std::cout << "original brain address: " << original.getBrain() << std::endl;
        std::cout << "copy brain address:     " << copy.getBrain() << std::endl;

        std::cout << "original idea[0] before mutation: "
                  << original.getBrain()->getIdea(0) << std::endl;
        std::cout << "copy idea[0] before mutation:     "
                  << copy.getBrain()->getIdea(0) << std::endl;

        original.getBrain()->setIdea(0, "chase the mailman");

        std::cout << "-- after mutating original --" << std::endl;
        std::cout << "original idea[0]: " << original.getBrain()->getIdea(0) << std::endl;
        std::cout << "copy idea[0]:     " << copy.getBrain()->getIdea(0) << std::endl;
    }

    std::cout << std::endl << "=== Deep copy test: Cat (copy assignment) ===" << std::endl;
    {
        Cat cat1;
        Cat cat2;

        cat1.getBrain()->setIdea(0, "knock things off tables");
        cat2.getBrain()->setIdea(0, "sleep 20 hours a day");

        cat2 = cat1;

        std::cout << "cat1 idea[0]: " << cat1.getBrain()->getIdea(0) << std::endl;
        std::cout << "cat2 idea[0]: " << cat2.getBrain()->getIdea(0) << std::endl;

        cat1.getBrain()->setIdea(0, "demand food at 5am");

        std::cout << "-- after mutating cat1 --" << std::endl;
        std::cout << "cat1 idea[0]: " << cat1.getBrain()->getIdea(0) << std::endl;
        std::cout << "cat2 idea[0]: " << cat2.getBrain()->getIdea(0) << std::endl;
    }

    return 0;
}
