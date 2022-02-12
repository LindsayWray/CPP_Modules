#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure"){
	std::cout << "Cure has been constructed\n";
}

Cure::Cure(Cure const& original) : AMateria(original){
	std::cout << "Cure has been copy-constructed\n";
}

Cure::~Cure(void){
	std::cout << "Cure has been destructed\n";
}

Cure& Cure::operator=(Cure const&){ //there are no properties in which two instances can differ
	return *this;
}

AMateria* Cure::clone() const{
	std::cout << "Cloning process started....\n";
	return new Cure();
}

void Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
