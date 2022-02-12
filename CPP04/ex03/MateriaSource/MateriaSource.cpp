#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	std::cout << "MateriaSource has been constructed\n";
	for(int i = 0; i < 4; i++)
		_materias[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const& original){
	std::cout << "MateriaSource has been copy-constructed\n";
	for(int i = 0; i < 4; i++){
		if (original._materias[i])
			_materias[i] = original._materias[i]->clone();
		else
			_materias[i] = NULL;
	}
}

MateriaSource::~MateriaSource(){
	std::cout << "MateriaSource has been destructed\n";
	for(int i = 0; i < 4; i++)
		delete _materias[i];
}

MateriaSource& MateriaSource::operator=(MateriaSource const& original){
	if (this == &original)
		return *this;
	for(int i = 0; i < 4; i++){
		delete _materias[i]; //test on NULL!!
		if (original._materias[i])
			_materias[i] = original._materias[i]->clone();
		else
			_materias[i] = NULL;
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* materia){
	if (!materia)
		return ;
	for(int i = 0; i < 4; i++){
		if(_materias[i] == NULL){
			_materias[i] = materia;
			std::cout	<< materia->getType() << " has been learned\n";
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const& type){ //can clone a previously learned materia
	for(int i = 0; i < 4; i++){
		if (_materias[i] && type == _materias[i]->getType()){
			std::cout	<< "materia "
						<< type
						<< " has been created and available to be equipped\n";
			return _materias[i]->clone();
		}
	}
	std::cout << type << " is unknown\n";
	return 0;
}
