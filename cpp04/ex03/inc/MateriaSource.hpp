#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "../inc/IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
//talvez colocar um tamanho maximo aqui
//e um array de ponteiros para AMateria
//para guardar as materias aprendidas

    
    public:
    MateriaSource();
    MateriaSource(const MateriaSource& other);
    MateriaSource& operator=(const MateriaSource& other);
    virtual ~MateriaSource();

    virtual void learnMateria(AMateria* materia);
    virtual AMateria* createMateria(std::string const & type);
};

#endif