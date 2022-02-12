#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <string>

class Weapon {

public:
	const std::string& getType(void);
	void setType(std::string weaponType);

	Weapon(std::string weapon_type);
	Weapon(void);
	~Weapon(void);

private:
	std::string _type;
};

#endif
