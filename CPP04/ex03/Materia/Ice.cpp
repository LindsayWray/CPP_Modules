#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice"){
	std::cout << "Ice has been constructed\n";
}

Ice::Ice(Ice const& original) : AMateria(original){
	std::cout << "Ice has been copy-constructed\n";
}

Ice::~Ice(void){
	std::cout << "Ice has been destructed\n";
}

Ice& Ice::operator=(Ice const&){ //there are no properties in which two instances can differ
	return *this;
}

AMateria* Ice::clone() const{
	std::cout << "Cloning process started....\n";
	return new Ice();
}

void Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
