#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include "../Character/ICharacter.hpp"
# include <string>
# include <iostream>

class ICharacter; // forward declaration to correct for circular dependency

class AMateria{
protected:
	std::string			const _type;	
public:

	AMateria(void);
	AMateria(std::string const& type);
	AMateria(AMateria const& original);
	virtual ~AMateria(void);

	AMateria&			operator=(AMateria const&);
	std::string const&	getType() const; //Returns the materia type
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);
};

#endif
