#include "Cat.hpp"
#include "Dog.hpp"

void	subjectTest(void){
	std::cout	<< "\nTest main provided by subject:\n"
				<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
}

void	catsAndDogs(){
	std::cout	<< "\nArray filled with dogs and cats:\n"
				<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

	Animal *catDogs [10];

	for(int i = 0; i < 10; i++){
		catDogs[i] = new Cat();
		i++;
		catDogs[i] = new Dog();
	}

	for(int i = 0; i < 10; i++){
		std::cout << "Type of animal: " << catDogs[i]->getType() << std::endl;
	}

	for(int i = 0; i < 10; i++){
		delete catDogs[i];
	}
}

void	deepcopies(){
	std::cout	<< "\nDeepcopies allocate a new memory space (for brain):\n"
				<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

	const Dog* Leika = new Dog();
	const Cat* Orion = new Cat();

	const Cat* CopyCat = new Cat(*Orion);
	const Dog* CopyDog = new Dog(*Leika);

	std::cout << "Leika's brain: " << Leika->getBrain() << std::endl;
	std::cout << "CopyDog's brain: " << CopyDog->getBrain() << std::endl;
	std::cout << "Orion's brain: " << Orion->getBrain() << std::endl;
	std::cout << "CopyCat's brain: " << CopyCat->getBrain() << std::endl;

	delete Leika;
	delete Orion;
	delete CopyDog;
	delete CopyCat;

	std::cout	<< "\nMore memory allocation testing:\n"
				<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

	Dog leika;
	Cat orion;

	Dog copyDog(leika);
	Cat copyCat(orion);

	std::cout << "Leika's brain: " << leika.getBrain() << std::endl;
	std::cout << "copyDog's brain: " << copyDog.getBrain() << std::endl;
	std::cout << "Orion's brain: " << orion.getBrain() << std::endl;
	std::cout << "copyCat's brain: " << copyCat.getBrain() << std::endl;
}

int	main(){
	subjectTest();
	catsAndDogs();
	deepcopies();

	// Animal Init;  <-- not possible anymore

	system("leaks animals");
}
