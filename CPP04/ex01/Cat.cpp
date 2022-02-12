# include "Cat.hpp"

Cat::Cat(void) : Animal("Cat"), _brain(new Brain){
	std::cout << "A kitten is born\n";
}

Cat::Cat(Cat const& original) 
	: Animal(original.getType()), _brain(new Brain(*(original._brain))){ // initialize brain with brain copyconstructor
	std::cout << "A copyCat has been created\n";
}

Cat::~Cat(void){
	delete _brain;
	std::cout << "This Cat is off to another realm\n";
}

Cat& Cat::operator=(Cat const& original){
	std::cout << "This Cat has been converted\n";
	if (this == &original)
		return *this;
	_type = original.getType();
	*_brain = *(original._brain); //overwrite current allocated memory with brain assignment operator. i.e. no need to delete
	return *this;
}

void	Cat::makeSound(void) const{
	std::cout << "* Miauw Miauw, am a Cat *\n";
}

Brain const*	Cat::getBrain(void) const{
	return _brain;
}
