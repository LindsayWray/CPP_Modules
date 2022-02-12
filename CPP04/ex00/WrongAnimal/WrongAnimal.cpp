# include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void){
	std::cout << "An animal is born\n";
}

WrongAnimal::WrongAnimal(std::string type) : _type(type){
	std::cout << "An animal is born\n";
}

WrongAnimal::WrongAnimal(WrongAnimal const& original) : _type(original._type){
	std::cout << "A copied animal has been created\n";
}

WrongAnimal::~WrongAnimal(void){
	std::cout << "This animal is off to another realm\n";
}

WrongAnimal&	WrongAnimal::operator=(WrongAnimal const& original){
	std::cout << "This animal has been converted\n";
	if (this == &original)
		return *this;
	_type = original.getType();
	return *this;
}

void	WrongAnimal::makeSound(void) const{
	std::cout << "* Generic animal noises *\n";
}

std::string WrongAnimal::getType() const{
	return this->_type;
}
