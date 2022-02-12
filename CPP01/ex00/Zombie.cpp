#include "Zombie.hpp"

Zombie::Zombie(void){
}

Zombie::~Zombie(void){
	std::cout << _name << " has finally found some peace" << std::endl;
}

void Zombie::announce(void){
	std::cout << _name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name){
	_name = name;
}
