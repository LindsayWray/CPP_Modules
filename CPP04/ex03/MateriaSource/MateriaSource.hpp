#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{
private:
	AMateria			*_materias[4];
	
public:
	MateriaSource();
	MateriaSource(MateriaSource const& original);
	virtual ~MateriaSource();

	MateriaSource&	operator=(MateriaSource const& original);
	void			learnMateria(AMateria*);
	AMateria*		createMateria(std::string const& type);
};

#endif
