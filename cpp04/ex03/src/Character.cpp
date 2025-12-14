#include "../inc/Character.hpp"

const int Character::_max_inv = 4;

Character::Character() : _name("NoName"), _count_equip(0) {}

Character::Character(const std::string name) : _name(name), _count_equip(0) {}

Character::Character(const Character& other) : _name(other._name), _count_equip(other._count_equip)
{
    for (int i = 0; i < _max_inv; i++)
    {
        if (other._materia[i])
            this->_materia[i] = other._materia[i];
        else
            this->_materia[i] = NULL;
    }
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        for (int i = 0; i < _max_inv; i++)
        {
            if (this->_materia[i])
            {
                delete _materia[i];
                this->_materia[i] = 
            
            }
        }
        this->_count_equip = other._count_equip;
    }
    return *this;
}

Character::~Character();
std::string const & Character::getName() const;
void Character::equip(AMateria* m);
void Character::unequip(int idx);
void Character::use(int idx, ICharacter& target);

AMateria* Character::getAMateria() const
{
    return _materia;
}