


#include "../inc/IMateriaSource.hpp"
#include "../inc/ICharacter.hpp"
#include "../inc/AMateria.hpp"

#include "../inc/MateriaSource.hpp"
#include "../inc/Character.hpp"
#include "../inc/Ice.hpp"
#include "../inc/Cure.hpp"

int main()
{
     // aqui crio o MateriaSource usando o ponteiro da interface IMateriaSource
    IMateriaSource* src = new MateriaSource();
    //como MateriaSource herda de IMateriaSource, posso usar o ponteiro da interface
     //para chamar os metodos implementados em MateriaSource
     //aprendo duas materias
    src->learnMateria(new Ice());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
    // // aqui crio um personagem usando o ponteiro da interface ICharacter
    // // como Character herda de ICharacter, posso usar o ponteiro da interface
    // // para chamar os metodos implementados em Character
    // // crio o personagem "me"
    ICharacter* me = new Character("me");
    // // aqui uso AMateria para criar materias do tipo "ice" e "cure"
    // // e equipar o personagem "me" com essas materias
    // // crio um ponteiro temporario para AMateria
    // // para armazenar as materias criadas
    // // e equipar o personagem "me"
    // // nao me posso esquecer de deletar as materias criadas
    // // mas sera que tem que ser feito no destruturor do Character?
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    // tmp = src->createMateria("cur");
    me->equip(tmp);
    // // uso as materias equipadas
    // // criando outro personagem "bob" para ser o alvo
    // // dos efeitos das materias
    ICharacter* bob = new Character("bob");
    bob->equip(tmp);
    std::cout << &bob << "   " << bob->getName() << std::endl;
    // // uso a materia no slot 0 (ice) no personagem bob
    // // uso a materia no slot 1 (cure) no personagem bob
    // // tento usar materias em slots invalidos
    // // slot 3 (vazio)
    // // slot 42 (fora do range)
    // // slot -1 (negativo)
    // // nao pode dar crash o programa nessas situacoes
    // delete bob;
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(3, *me);  // empty slot
    // me->use(42, *bob); // out of range
    // me->use(-1, *bob); // negative index
    // // acho que sou obrigado a deletar tudo o que criei com new
    // // para evitar memory leaks
    // // ou sera que o destrutor do Character ja cuida disso?
    // // ainda nao sei, para nao ter double free ou invalid free
    delete bob;
    // // deletar o personagem "me" deve deletar as materias equipadas
    // // entao nao preciso deletar as materias uma a uma
    // // antes de deletar o personagem "me"
    // // mas e o MateriaSource?
    // // ele deve deletar as materias que aprendeu?
    // // acho que sim, entao nao preciso deletar as materias uma a uma
    // // antes de deletar o MateriaSource
    // // entao so preciso deletar o personagem "me" e o MateriaSource
    delete me;
    delete src;
    return 0;
}

