#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
public:

	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const& original);
	~ScavTrap(void);
	
	ScavTrap& operator=(ScavTrap const& original);

	void attack(std::string const& target);
	void attack(ClapTrap& target);
	void guardGate();
private:
	bool	_isGuarding;
};

#endif
