#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "../inc/ICharacter.hpp"

class Character : public ICharacter
{
    private:
// talvez um array de ponteiros para AMateria
// e um nome
// um tamanho maximo de inventario
// e um contador de materias equipadas
// para gerenciar o inventario

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