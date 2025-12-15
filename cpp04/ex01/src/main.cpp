

#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"


int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    j->makeSound();
    i->makeSound();

    Dog first;
    first.getBrain()->setIdea(0,"oiiiiiii");

    Dog dog(first);
    std::cout << dog.getBrain()->getIdea(0) << std::endl;

    dog.getBrain()->setIdea(0,"hello");

    std::cout << dog.getBrain()->getIdea(0) << std::endl;
    std::cout << first.getBrain()->getIdea(0) << std::endl;

    delete j; 
    delete i;

    Animal* animals[10];
    for (int index = 0; index < 10; index++)
    {
        if (index % 2 == 0)
            animals[index] = new Dog();
        else
            animals[index] = new Cat();
    }

    for (int index = 0; index < 10; index++)
        animals[index]->makeSound();
    
    for (int index = 0; index < 10; index++)
        delete animals[index];

    Dog* dog1 = new Dog();

    dog1->getBrain()->setIdea(2, "I have brain HUHU -> dog");
    std::cout << dog1->getBrain()->getIdea(2) << std::endl;
    std::cout << dog1->getBrain()->getIdea(100) << std::endl;

    delete dog1;
    return 0;
}
