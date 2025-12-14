#include "../inc/MateriaSource.hpp"



MateriaSource::MateriaSource() 
{
    for (int i = 0; i < 4; i++)
        _materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    for (int i = 0; i < 4; i++)
        this->_materia[i] = other._materia[i]->clone();
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->_materia[i])
                delete _materia[i];
            if (other._materia[i])
                this->_materia[i] = other._materia[i]->clone();
        }
    }
    return *this;
}
// limpar aqui o alocado das materias?
MateriaSource::~MateriaSource() 
{
    for (int i = 0; i < 4; i++)
    {
        if (_materia[i])
            delete _materia[i];
    }
}

void MateriaSource::learnMateria(AMateria* materia)
{
    if (!materia)
    {
        std::cout << "Wrong Materia to learn!" << std::endl;
        return ;
    }
    for (int i = 0; i < 4; i++)
    {
        if (!_materia[i])
        {
            _materia[i] = materia;
            return ;
        }
    }
    std::cout << "Materia Full! I have only 4 slots to learn!" << std::endl;
    //caso esteja cheio, apagar aqui o material que esta a ser criado!
    // senao da leaks.
    delete materia;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        // verificar antes se o ponteiro tem algo para ir buscar o type.
        if (_materia[i] && _materia[i]->getType() == type) 
            return _materia[i];
    }
    std::cout << "Unknown Material to create! Please learn first."
              << std::endl;
    return NULL;
}