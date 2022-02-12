#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include "WrongAnimal.hpp"

class	WrongCat: public WrongAnimal{
public:

	WrongCat(void);
	WrongCat(WrongCat const& original);
	~WrongCat(void);

	WrongCat&	operator=(WrongCat const& original);
	void	makeSound(void) const;
};

#endif
