
#include <iostream>

int main(void) 
{
    std::string brain = "HI THIS IS BRAIN";
    std::string* Pbrain = &brain;
    std::string& Rbrain = brain;

    std::cout << &brain << std::endl;
    std::cout << &Pbrain << std::endl;
    std::cout << &Rbrain << std::endl;

    std::cout << "Value of string: " << brain << std::endl;
    std::cout << "Value of stringPTR: " << *Pbrain << std::endl;
    std::cout << "Value of stringREF: " << Rbrain << std::endl;
    return 0;
}