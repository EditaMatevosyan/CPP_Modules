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
        i->makeSound();
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
        wc->makeSound();

        delete wa;
        delete wc;
    }

    std::cout << std::endl << "=== Direct (non-base-pointer) calls ===" << std::endl;
    {
        Dog realDog;
        Cat realCat;
        WrongCat realWrongCat;

        realDog.makeSound();
        realCat.makeSound();
        realWrongCat.makeSound();
    }

    std::cout << std::endl << "=== Copy constructor test ===" << std::endl;
    {
        Dog original;
        Dog copy(original);

        std::cout << "original type: " << original.getType() << std::endl;
        std::cout << "copy type: " << copy.getType() << std::endl;
    }

    std::cout << std::endl << "=== Copy assignment operator test ===" << std::endl;
    {
        Cat cat1;
        Cat cat2;

        std::cout << "cat2 type before assignment: " << cat2.getType() << std::endl;
        cat2 = cat1;
        std::cout << "cat2 type after assignment: " << cat2.getType() << std::endl;

        Cat* catPtr = &cat2;
        cat2 = *catPtr;
        std::cout << "cat2 type after self-assignment: " << cat2.getType() << std::endl;
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