


#include "../inc/IMateriaSource.hpp"
#include "../inc/ICharacter.hpp"
#include "../inc/AMateria.hpp"

#include "../inc/MateriaSource.hpp"
#include "../inc/Character.hpp"
#include "../inc/Ice.hpp"
#include "../inc/Cure.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");

    me->equip(tmp);

    ICharacter* bob = new Character("bob");
    bob->equip(tmp);

    me->use(0, *bob);
    me->use(1, *bob);
    me->use(3, *me);  // empty slot

    delete bob;

    delete me;
    delete src;
    return 0;
}

