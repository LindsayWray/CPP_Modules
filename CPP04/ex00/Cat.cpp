# include "Cat.hpp"

Cat::Cat(void) : Animal("Cat"){
	std::cout << "A kitten is born\n";
}

Cat::Cat(Cat const& original) : Animal(original.getType()){
	std::cout << "A copyCat has been created\n";
}

Cat::~Cat(void){
	std::cout << "This Cat is off to another realm\n";
}

Cat& Cat::operator=(Cat const& original){
	std::cout << "This Cat has been converted\n";
	if (this == &original)
		return *this;
	_type = original.getType();
	return *this;
}

void	Cat::makeSound(void) const{
	std::cout << "* Miauw Miauw, am a Cat *\n";
}
