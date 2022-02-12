#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap{
public:

	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(FragTrap const& original);
	~FragTrap(void);
	
	FragTrap& operator=(FragTrap const& original);

	void highFivesGuys(void);
protected:
	static const int _initHP = 100;
	static const int _initAttackDamage = 30;
	static const int _initEnergy = 100;
};

#endif
