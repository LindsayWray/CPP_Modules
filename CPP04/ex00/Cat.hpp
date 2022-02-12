#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"

class	Cat: public Animal{
public:

	Cat(void);
	Cat(Cat const& original);
	virtual ~Cat(void);

	Cat&	operator=(Cat const& original);
	void	makeSound(void) const;
};

#endif
