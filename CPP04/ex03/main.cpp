#include "Materia/Cure.hpp"
#include "Materia/Ice.hpp"
#include "Character/Character.hpp"
#include "MateriaSource/MateriaSource.hpp"

void	subjectTest(){
	std::cout	<< "\nSubject main testing\n"
				<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
}

void	equipTesting(){
	std::cout	<< "\nEquip and Unequip testing\n"
			<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	Character* Wizard = new Character("White Beard");
	Character* Goblin = new Character("Gobby");
	Ice* icy = new Ice;
	Wizard->equip(icy);
	Wizard->use(3, *Goblin); //nothing available
	Wizard->use(0, *Goblin);
	Wizard->equip(new Cure());
	Wizard->use(1, *Goblin);
	Wizard->unequip(0);
	delete icy;  //The unequip method must NOT delete Materia!, see subject
	Wizard->use(0, *Goblin);
	Wizard->equip(new Cure());
	Wizard->equip(new Cure());
	Wizard->equip(new Ice());
	Wizard->equip(new Cure()); //this materia does not fit
	Wizard->use(2, *Wizard);
	delete Wizard;
	delete Goblin;
}

int main()
{
	subjectTest();
	equipTesting();
	system ("leaks interface");
}
