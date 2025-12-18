

#include "../inc/Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat first;
        for (int i = 0; i < 44; i++)
        {
            std::cout << first << std::endl;
            first.increment();
        }
    }
    catch(std::exception& e) // porque o exception::what e virtual e chama a exceccao correta.
    {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}