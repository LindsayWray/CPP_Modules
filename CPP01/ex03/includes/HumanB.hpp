#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"

class HumanB {

public:

	void	attack(void);
	void	setWeapon(Weapon& type);

	HumanB(std::string name);
	~HumanB(void);

private:
	std::string	_name;
	Weapon		*_weapon_type;
};

#endif
