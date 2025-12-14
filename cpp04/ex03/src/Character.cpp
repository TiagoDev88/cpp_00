

#include "Character.hpp"

Character::Character(const std::string name) : _name(name)
{
    for (int i = 0; i < _inventorySize; i++)
        _inventory[i] = NULL;
}

Character::Character(const Character& other) : _name(other._name)
{
    for (int i = 0; i < _inventorySize; i++)
        _inventory[i] = NULL;
    *this = other;
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        _name = other._name;
        for (int i = 0; i < _inventorySize; i++)
        {
            if (_inventory[i])
            {
                delete _inventory[i];
                _inventory[i] = NULL;
            }
            if (other._inventory[i])
                _inventory[i] = other._inventory[i]->clone();
        }
    }
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < _inventorySize; i++)
    {
        if (_inventory[i])
            delete _inventory[i];
    }
}

std::string const & Character::getName() const
{
    return _name;
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < _inventorySize; i++)
    {
        if (_inventory[i] == NULL)
        {
            _inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < _inventorySize)
    {
        _inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < _inventorySize && _inventory[idx])
    {
        _inventory[idx]->use(target);
    }
}

