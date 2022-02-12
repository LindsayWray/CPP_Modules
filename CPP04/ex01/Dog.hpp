#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class	Dog: public Animal{
private:
	Brain* _brain;
public:
	Dog(void);
	Dog(Dog const& original);
	virtual ~Dog(void);

	Dog&	operator=(Dog const& original);
	
	void			makeSound(void) const;
	Brain const*	getBrain(void) const;
};

#endif
