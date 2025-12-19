

#include "../inc/Bureaucrat.hpp"

void testToHigh();
void testToLow();

int main(void)
{
    testToHigh();
    testToLow();

    return 0;
}

void testToHigh()
{
    try
    {
        Bureaucrat first;
        for (int i = 0; i < 20; i++)
        {
            std::cout << first << std::endl;
            first.increment();
        }
        std::cout << std::endl;

        Bureaucrat s1 = first;
        for (int i = 0; i < 20; i++)
        {
            std::cout << s1 << std::endl;
            s1.increment();
        }
        std::cout << std::endl;
        
        Bureaucrat s("Kiko", 0);
        for (int i = 0; i < 20; i++)
        {
            std::cout << s << std::endl;
            s.increment();
        }
        std::cout << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void testToLow()
{
    try
    {
        Bureaucrat first("Kiko", 130);
        for (int i = 0; i < 20; i++)
        {
            std::cout << first << std::endl;
            first.decrement();
        }
        std::cout << std::endl;

        Bureaucrat s1 = first;
        for (int i = 0; i < 20; i++)
        {
            std::cout << s1 << std::endl;
            s1.decrement();
        }
        std::cout << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}