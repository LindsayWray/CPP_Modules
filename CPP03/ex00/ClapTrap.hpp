#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>
#include <iostream> 

class ClapTrap{
public:

	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const& original);
	~ClapTrap(void);

	ClapTrap& operator=(ClapTrap const& original);
	void	attack(std::string const& target);
	void	attack(ClapTrap& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

private:
	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;
};

#endif
