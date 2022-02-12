# include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("Cat"){
	std::cout << "A kitten is born\n";
	_type = "Cat";
}

WrongCat::WrongCat(WrongCat const& original){
	std::cout << "A copyCat has been created\n";
	_type = original.getType();
}

WrongCat::~WrongCat(void){
	std::cout << "This Cat is off to another realm\n";
}

WrongCat& WrongCat::operator=(WrongCat const& original){
	std::cout << "This Cat has been converted\n";
	if (this == &original)
		return *this;
	_type = original.getType();
	return *this;
}

void	WrongCat::makeSound(void) const{
	std::cout << "* Miauw Miauw, am a Cat *\n";
}
