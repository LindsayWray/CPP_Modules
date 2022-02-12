#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap{
public:

	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const& original);
	~ScavTrap(void);
	
	ScavTrap& operator=(ScavTrap const& original);

	void attack(std::string const& target);
	void attack(ClapTrap& target);
	void guardGate();
protected:
	bool				_isGuarding;
	static const int 	_initHP = 100;
	static const int 	_initAttackDamage = 20;
	static const int	_initEnergy = 50;
};

#endif
