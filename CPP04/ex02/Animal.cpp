# include "Animal.hpp"

Animal::Animal(void){
	std::cout << "An animal is born\n";
}

Animal::Animal(std::string type) : _type(type){
	std::cout << "An animal is born\n";
}

Animal::Animal(Animal const& original) : _type(original._type){
	std::cout << "A copied animal has been created\n";
}

Animal::~Animal(void){
	std::cout << "This animal is off to another realm\n";
}

Animal&	Animal::operator=(Animal const& original){
	std::cout << "This animal has been converted\n";
	if (this == &original)
		return *this;
	_type = original.getType();
	return *this;
}

std::string Animal::getType() const{
	return this->_type;
}
