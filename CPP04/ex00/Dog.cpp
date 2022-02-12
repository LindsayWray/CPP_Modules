# include "Dog.hpp"

Dog::Dog(void) : Animal("Dog"){
	std::cout << "A puppy is born\n";
}

Dog::Dog(Dog const& original) : Animal(original.getType()){
	std::cout << "A copyDog has been created\n";
}

Dog::~Dog(void){
	std::cout << "This Dog is off to another realm\n";
}

Dog& Dog::operator=(Dog const& original){
	std::cout << "This Dog has been converted\n";
	if (this == &original)
		return *this;
	_type = original.getType();
	return *this;
}

void	Dog::makeSound(void) const{
	std::cout << "* Woof Woof, am a Dog *\n";
}
