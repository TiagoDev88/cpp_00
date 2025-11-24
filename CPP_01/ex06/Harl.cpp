


#include "Harl.hpp"

Harl::Harl(void) {};

Harl::~Harl(void) {};

void Harl::debug( void )
{
    std::cout << "DEBUG\n";
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
    std::cout << "INFO\n";
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void )
{
    std::cout << "WARNING\n";
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error( void )
{
    std::cout << "ERROR\n";
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*input[4])(void) = {
        &Harl::debug, 
        &Harl::info, 
        &Harl::warning, 
        &Harl::error}; // array -> pointers to member functions
    int i;
    for (i = 0; i < 4; i++)
    {
        if (level == levels[i])
            break;
    }

    switch (i)
    {
    case 0:
        (this->*input[i])();
        break;
    case 1:
        (this->*input[i])();
        break;
    case 2:
        (this->*input[i])();
        break;
    case 3:
        (this->*input[i])();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        break;
    }
}