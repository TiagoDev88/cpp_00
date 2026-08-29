#include "Base.hpp"
#include <ctime>

int main(void)
{
    std::srand(std::time(NULL));

    for (int i = 0; i < 10; ++i)
    {
        Base* p = NULL;

        std::cout << "identify(Base*): ";
        identify(p);

        std::cout << "identify(Base&): ";
        identify(*p);

        std::cout << "-----" << std::endl;

        delete p;
    }
    return 0;
}
