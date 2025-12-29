

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

void testFormValid()
{
    std::cout << "------Form Valid-------" << std::endl;
    try
    {
        Form v1("Social Security nr 202", 50, 32);
        Bureaucrat kiko("Francisco", 9);

        std::cout << v1 << std::endl;
        v1.beSigned(kiko);
        kiko.signForm(v1);
        std::cout << v1 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

void testFormNotValidTooLow()
{
    std::cout << "\n------Form Not Valid, Too Low-------" << std::endl;
    try
    {
        Form v1("Social Security nr 42", 50, 32);
        Bureaucrat kiko("Jose", 51);

        std::cout << v1 << std::endl;
        v1.beSigned(kiko);
        kiko.signForm(v1);
        std::cout << v1 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

void testFormNotValidTooHigh()
{
    std::cout << "\n------Form Not Valid, Too High-------" << std::endl;
    try
    {
        Form v1("Social Security nr 100", 50, 32);
        Bureaucrat kiko("Manel", 1);

        std::cout << v1 << std::endl;
        v1.beSigned(kiko);
        kiko.signForm(v1);
        std::cout << v1 << std::endl;
        kiko.increment();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

int main(void)
{
    testFormValid();
    testFormNotValidTooLow();
    testFormNotValidTooHigh();
    return 0;
}

