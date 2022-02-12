# include "Dog.hpp"

Dog::Dog(void) : Animal("Dog"), _brain(new Brain){
	std::cout << "A puppy is born\n";
}

Dog::Dog(Dog const& original)
	: Animal(original.getType()), _brain(new Brain(*(original._brain))){ // initialize brain with brain copyconstructor
	std::cout << "A copyDog has been created\n";
}

Dog::~Dog(void){
	delete _brain;
	std::cout << "This Dog is off to another realm\n";
}

Dog& Dog::operator=(Dog const& original){
	std::cout << "This Dog has been converted\n";
	if (this == &original)
		return *this;
	_type = original.getType();
	*_brain = *(original._brain); //overwrite current allocated memory with brain assignment operator. i.e. no need to delete
	return *this;
}

void	Dog::makeSound(void) const{
	std::cout << "* Woof Woof, am a Dog *\n";
}

Brain const*	Dog::getBrain(void) const{
	return _brain;
}
