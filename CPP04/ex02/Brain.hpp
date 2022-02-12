#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>
# include <iostream>

class Brain{
private:
	std::string _ideas[100];
public:

	Brain(void);
	Brain(Brain const& original);
	virtual ~Brain(void);

	Brain& operator=(Brain const& original);
	std::string const*	getIdeas() const;
};

#endif
