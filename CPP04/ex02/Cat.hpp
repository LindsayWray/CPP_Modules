#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class	Cat: public Animal{
private:
	Brain* _brain;
public:

	Cat(void);
	Cat(Cat const& original);
	virtual ~Cat(void);

	Cat&	operator=(Cat const& original);
	
	void			makeSound(void) const;
	Brain const*	getBrain(void) const;
};

#endif
