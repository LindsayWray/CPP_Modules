# include "Character.hpp"

Character::Character(){
	std::cout << "Character " << _name << " has been constructed\n";
	for(int i = 0; i < 4; i++)
		_materias[i] = NULL;
}

Character::Character(std::string name) : _name(name){
	std::cout << "Character " << _name << " has been constructed\n";
	for(int i = 0; i < 4; i++)
		_materias[i] = NULL;
}


Character::Character(Character const& original) : _name(original._name){
	std::cout << "Character " << _name << " has been copy-constructed\n";
	for(int i = 0; i < 4; i++){
		if (original._materias[i])
			_materias[i] = original._materias[i]->clone();
		else
			_materias[i] = NULL;
	}
}

Character::~Character(){
	std::cout << "Character " << _name << " has been destructed\n";
	for(int i = 0; i < 4; i++)
		delete _materias[i];
}

Character& Character::operator=(Character const& original){
	if (this == &original)
		return *this;
	_name = original._name;
	for(int i = 0; i < 4; i++){
		delete _materias[i]; //test on NULL!!
		if (original._materias[i])
			_materias[i] = original._materias[i]->clone();
		else
			_materias[i] = NULL;
	}
	return *this;
}

std::string const& Character::getName() const{
	return _name;
}

void Character::equip(AMateria* materia){
	if (!materia)
		return ;
	for(int i = 0; i < 4; i++){
		if (_materias[i] == NULL){
			_materias[i] = materia;
			std::cout	<< "Character "
						<< _name
						<< " has equipped "
						<< materia->getType()
						<< " on index: "
						<< i << std::endl;
			return ;
		}
	}
	std::cout << "No more space to store more AMateria\n";
	delete materia; //cleans up materia in case array is already full
}

void Character::unequip(int index){
	if (index >= 0 && index < 4 && _materias[index]){
		std::cout	<< "Character "
					<< _name
					<< " has unequipped "
					<< _materias[index]->getType()
					<< " on index: "
					<< index << std::endl;
		_materias[index] = NULL;
	}
}

void Character::use(int index, ICharacter& target){
	if (index >= 0 && index < 4 && _materias[index])
		_materias[index]->use(target);
	else
		std::cout << "No AMateria available on index: " << index << std::endl;
}
