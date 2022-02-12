#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"

class HumanA {

public:

	void attack(void); 

	HumanA(std::string name, Weapon& type);
	~HumanA(void);

private:
	std::string	_name;
	Weapon&		_weapon_type; //saves a reference to this particular weapon, so this way you can alter this weapon.
};

#endif
