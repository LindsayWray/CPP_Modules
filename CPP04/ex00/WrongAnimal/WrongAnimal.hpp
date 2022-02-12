#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <string>
# include <iostream>

class	WrongAnimal{
public:
	WrongAnimal(void);
	WrongAnimal(std::string type);
	WrongAnimal(WrongAnimal const& original);
	virtual ~WrongAnimal(void);

	WrongAnimal&	operator=(WrongAnimal const& original);
	std::string	getType() const;
	void	makeSound(void) const;

protected:
	std::string	_type;
};

#endif
