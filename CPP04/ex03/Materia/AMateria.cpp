#include "AMateria.hpp"

AMateria::AMateria(void){
	std::cout << "AMateria has been constructed\n";
}

AMateria::AMateria(std::string const& type) : _type(type){
	std::cout << "AMateria of type " << _type << " has been constructed\n";
}

AMateria::AMateria(AMateria const& original) : _type(original._type){
	std::cout << "AMateria of type " << _type << " has been copy-constructed\n";
}

AMateria::~AMateria(void){
	std::cout << "AMateria of type " << _type << " has been destructed\n";
}

AMateria& AMateria::operator=(AMateria const&){
	return *this;
}

std::string const& AMateria::getType() const{
	return _type;
}

void AMateria::use(ICharacter& target){
	std::cout << "Does generic " << _type << " effect against " << target.getName() << std::endl;
}
