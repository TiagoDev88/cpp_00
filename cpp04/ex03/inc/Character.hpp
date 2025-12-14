#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "../inc/ICharacter.hpp"
#include "../inc/AMateria.hpp"

class Character : public ICharacter
{
    private:
// talvez um array de ponteiros para AMateria
    AMateria*       _slot[4];
// e um nome
    std::string     _name;
// um tamanho maximo de inventario
    static const int _maxInv;
// e um contador de materias equipadas
// para gerenciar o inventario
    int              _countEquip;

    public:
    Character();
    Character(const std::string name);
    Character(const Character& other);
    Character& operator=(const Character& other);
    virtual ~Character();

    virtual std::string const & getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);

};

#endif