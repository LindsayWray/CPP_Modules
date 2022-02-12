#include "Zombie.hpp"

Zombie::Zombie(void){
}

Zombie::~Zombie(void){
	std::cout << this->_name << " has finally found some peace" << std::endl;
}

void Zombie::announce(void){
	std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name){
	this->_name = name;
}
