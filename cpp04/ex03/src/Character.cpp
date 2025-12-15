#include "../inc/Character.hpp"

const int Character::_maxInv = 4;

Character::Character() : _name("NoName"), _countEquip(0) 
{
    for (int i = 0; i < _maxInv; i++)
        _slot[i] = NULL;
}

Character::Character(const std::string name) : _name(name), _countEquip(0) 
{
    for (int i = 0; i < _maxInv; i++)
        _slot[i] = NULL;
}

Character::Character(const Character& other) : _name(other._name), _countEquip(other._countEquip)
{
    for (int i = 0; i < _maxInv; i++)
    {
        if (other._slot[i])
            this->_slot[i] = other._slot[i]->clone();
        else
            this->_slot[i] = NULL;
    }
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        this->_countEquip = other._countEquip;
        this->_name = other._name;
        for (int i = 0; i < _maxInv; i++)
        {
            if (this->_slot[i])
            {
                delete _slot[i];
                this->_slot[i] = NULL;
            }
            if (other._slot[i])
            {
                this->_slot[i] = other._slot[i]->clone();
                this->_countEquip++;
            }
        }
    }
    return *this;
}

Character::~Character() 
{
    for (int i = 0; i < _maxInv; i++)
    {
        if (_slot[i])
            delete _slot[i];
    }
}

std::string const & Character::getName() const { return _name; }

void Character::equip(AMateria* m)
{
    if (_countEquip < 0 || _countEquip > 3 || !m)
        return;
    for (int i = 0; i < _maxInv; i++)
    {
        if (!_slot[i])
        {
            _slot[i] = m->clone();
            std::cout << _name << " equip Materia " << m->getType()
                      << " in slot " << i << std::endl;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3)
    {
        std::cout << "Slot out of range! " << std::endl;
        return;
    }

    if (_slot[idx])
    {
        std::cout << _slot[idx]->getType() << " unequip from slot "
                  << idx << std::endl;
        delete _slot[idx];
        _slot[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx > 3)
    {
        std::cout << "Slot out of range" << std::endl;
        return;
    }
    if (!this->_slot[idx])
    {
        std::cerr << "Invalid Materia or empty slot!"
                  << " please equip one valid materia!"
                  << std::endl;
        return;
    }
    this->_slot[idx]->use(target);
}

