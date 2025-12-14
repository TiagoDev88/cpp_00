
#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _learnedCount(0)
{
    for (int i = 0; i < _maxMateria; i++)
        _materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) : _learnedCount(0)
{
    for (int i = 0; i < _maxMateria; i++)
        _materias[i] = NULL;
    *this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        for (int i = 0; i < _maxMateria; i++)
        {
            if (_materias[i])
            {
                delete _materias[i];
                _materias[i] = NULL;
            }
            if (other._materias[i])
                _materias[i] = other._materias[i]->clone();
        }
        _learnedCount = other._learnedCount;
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < _maxMateria; i++)
    {
        if (_materias[i])
            delete _materias[i];
    }
}

void MateriaSource::learnMateria(AMateria* materia)
{
    if (_learnedCount < _maxMateria && materia)
    {
        _materias[_learnedCount] = materia;
        _learnedCount++;
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < _learnedCount; i++)
    {
        if (_materias[i] && _materias[i]->getType() == type)
            return _materias[i]->clone();
    }
    return NULL;
}

