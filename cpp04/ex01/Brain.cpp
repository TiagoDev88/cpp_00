

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Constructor Brain default called" << std::endl;
}

Brain::Brain(const Brain& other)
{
    std::cout << "Copy Constructor Brain called" << std::endl;
    for (int i = 0; i < 100; ++i)
        _ideas[i] = other._ideas[i];
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Copy assignment operator Brain called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; ++i)
            this->_ideas[i] = other._ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Destructor Brain called" << std::endl;
}

std::string Brain::getIdea(size_t index) const
{
    if (index >= 100)
    {
        std::cerr << "Index out of range, please choose from 0 to 99"
                  << std::endl;
        return ("");
    }
    return (this->_ideas[index]);
}

void Brain::setIdea(size_t index, std::string idea)
{
    if (index >= 100)
    {
        std::cout << index << std::endl;
        std::cerr << "Index out of range, please choose from 0 to 99"
                  << std::endl;
        return;
    }
    this->_ideas[index] = idea;
}