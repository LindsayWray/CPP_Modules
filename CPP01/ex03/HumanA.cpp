#include "includes/HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string human_name, Weapon& type) : _name(human_name), _weapon_type(type){
}

HumanA::~HumanA(void){
}

void HumanA::attack(void){
	std::cout 	<< _name
				<< " attacks with their "
				<< _weapon_type.getType()
				<< std::endl;
}
