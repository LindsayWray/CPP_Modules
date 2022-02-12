#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>
# include <iostream>

class	Animal{
protected:
	std::string	_type;
	Animal(std::string type);
public:
	Animal(void);
	Animal(Animal const& original);
	virtual ~Animal(void);	/* Note: If the base class destructor does not use a virtual keyword, only the base class destructor will
							be called or deleted its occupied space because the pointer object is pointing to the base class. 
							So it does not call the derived class destructor to free the memory used by the derived class,
							which leads to memory leak for the derived class. */

	Animal&	operator=(Animal const& original);
	std::string	getType() const;
	virtual void	makeSound(void) const;
};

#endif
