#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "=== Subject example ===" << std::endl;
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); // will output the cat sound!
        j->makeSound();
        meta->makeSound();

        delete meta;
        delete j;
        delete i;
    }

    std::cout << std::endl << "=== WrongAnimal / WrongCat test ===" << std::endl;
    {
        const WrongAnimal* wa = new WrongAnimal();
        const WrongAnimal* wc = new WrongCat();

        std::cout << wa->getType() << " " << std::endl;
        std::cout << wc->getType() << " " << std::endl;
        wa->makeSound();
        wc->makeSound(); // should wrongly output WrongAnimal sound, NOT WrongCat's

        delete wa;
        delete wc;
    }

    std::cout << std::endl << "=== Direct (non-base-pointer) calls ===" << std::endl;
    {
        Dog realDog;
        Cat realCat;
        WrongCat realWrongCat;

        realDog.makeSound();       // barf barf
        realCat.makeSound();       // myauuu
        realWrongCat.makeSound();  // phrrrrr (called directly, so it's fine here)
    }

    std::cout << std::endl << "=== Deep copy test (copy constructor) ===" << std::endl;
    {
        Dog original;
        original.getBrain()->setIdea(0, "I want a bone");

        Dog copy(original);

        std::cout << "brain address -> original: " << original.getBrain()
                  << " | copy: " << copy.getBrain() << std::endl;
        std::cout << "idea 0 -> original: " << original.getBrain()->getIdea(0)
                  << " | copy: " << copy.getBrain()->getIdea(0) << std::endl;

        original.getBrain()->setIdea(0, "Actually I want two bones");

        std::cout << "after changing the original's idea:" << std::endl;
        std::cout << "idea 0 -> original: " << original.getBrain()->getIdea(0)
                  << " | copy: " << copy.getBrain()->getIdea(0) << std::endl;
        std::cout << "copy kept its own idea => deep copy" << std::endl;
    }

    std::cout << std::endl << "=== Deep copy test (copy assignment) ===" << std::endl;
    {
        Cat cat1;
        Cat cat2;

        cat1.getBrain()->setIdea(0, "The red dot is mine");
        cat2.getBrain()->setIdea(0, "I hate the vacuum");

        std::cout << "idea 0 before assignment -> cat1: " << cat1.getBrain()->getIdea(0)
                  << " | cat2: " << cat2.getBrain()->getIdea(0) << std::endl;

        cat2 = cat1;

        std::cout << "brain address -> cat1: " << cat1.getBrain()
                  << " | cat2: " << cat2.getBrain() << std::endl;
        std::cout << "idea 0 after assignment -> cat1: " << cat1.getBrain()->getIdea(0)
                  << " | cat2: " << cat2.getBrain()->getIdea(0) << std::endl;

        cat1.getBrain()->setIdea(0, "Feed me at 5am");

        std::cout << "after changing cat1's idea:" << std::endl;
        std::cout << "idea 0 -> cat1: " << cat1.getBrain()->getIdea(0)
                  << " | cat2: " << cat2.getBrain()->getIdea(0) << std::endl;
        std::cout << "cat2 kept its own idea => deep copy" << std::endl;

        // self-assignment guard test (indirection avoids -Wself-assign-overloaded)
        Cat* catPtr = &cat2;
        cat2 = *catPtr;
        std::cout << "cat2 idea 0 after self-assignment: "
                  << cat2.getBrain()->getIdea(0) << std::endl;
    }

    std::cout << std::endl << "=== Array of base-class pointers ===" << std::endl;
    {
        Animal* animals[4];
        animals[0] = new Dog();
        animals[1] = new Cat();
        animals[2] = new Dog();
        animals[3] = new Cat();

        for (int k = 0; k < 4; k++)
        {
            std::cout << animals[k]->getType() << ": ";
            animals[k]->makeSound();
        }
        for (int k = 0; k < 4; k++)
            delete animals[k];
    }

    return 0;
}