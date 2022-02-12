#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
public:

	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(FragTrap const& original);
	~FragTrap(void);
	
	FragTrap& operator=(FragTrap const& original);

	void highFivesGuys(void);
};

#endif
