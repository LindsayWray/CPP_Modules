#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap{
public:

	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(DiamondTrap const& original);
	~DiamondTrap(void);

	DiamondTrap& operator=(DiamondTrap const& original);

	void whoAmI(void);
private:
	std::string	_name;
};

#endif
