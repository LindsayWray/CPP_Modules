#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"

class Cure : public AMateria{
public:

	Cure(void);
	Cure(Cure const& original);
	virtual ~Cure(void);

	Cure&		operator=(Cure const&);
	AMateria*	clone() const;
	void		use(ICharacter& target);
};

#endif
