#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal/WrongCat.hpp"

void	subjectTest(void){
	std::cout	<< "\nTest main provided by subject:\n"
				<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete i;
	delete j;
	delete meta;
}

void	wrongcatTest(){
	std::cout	<< "\nTest wrongcat making wrong sound\n"
				<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	const WrongAnimal* fauxCat = new WrongCat();
	std::cout << "Type of animal: " << fauxCat->getType() << std::endl;
	fauxCat->makeSound();
	delete fauxCat;
}

void	classBasicsTest(void){
	std::cout	<< "\nTest class basics\n"
				<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	Animal Human;
	std::cout << "Type of animal: " << Human.getType() << std::endl;
	Human.makeSound();
	Cat Spot;
	std::cout << "Type of animal: " << Spot.getType() << std::endl;
	Spot.makeSound();
	Dog Leika;
	std::cout << "Type of animal: " << Leika.getType() << std::endl;
	Leika.makeSound();
	Human = Spot;
	std::cout << "Type of animal: " << Human.getType() << std::endl;
	Human.makeSound(); // still calls the makesound as an animal
	Cat Imposter(Spot);
	std::cout << "Type of animal: " << Imposter.getType() << std::endl;
	Imposter.makeSound();
}

int	main(){
	subjectTest();
	wrongcatTest();
	classBasicsTest();

	//system ("leaks animals");
}
