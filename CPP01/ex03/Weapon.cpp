#include "includes/Weapon.hpp"

Weapon::Weapon(std::string weapon_type) : _type(weapon_type){
}

Weapon::Weapon(void){
}

Weapon::~Weapon(void){
}

const std::string& Weapon::getType(void){
	return _type;
}

void Weapon::setType(std::string weaponType){
	_type = weaponType;
}
