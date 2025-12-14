#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
    private:
    static const int    _maxMateria = 4;
    AMateria*           _materias[_maxMateria];
    int                 _learnedCount;
    
    public:
    MateriaSource();
    MateriaSource(const MateriaSource& other);
    MateriaSource& operator=(const MateriaSource& other);
    virtual ~MateriaSource();

    virtual void learnMateria(AMateria* materia);
    virtual AMateria* createMateria(std::string const & type);
};

#endif