#include "includes/HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string human_name) : _name(human_name){
}

void HumanB::setWeapon(Weapon& type){
	_weapon_type = &type;
}

HumanB::~HumanB(void){
}

void HumanB::attack(void){
	std::cout 	<< _name
				<< " attacks with their "
				<< _weapon_type->getType()
				<< std::endl;
}
