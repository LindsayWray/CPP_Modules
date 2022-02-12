#include "FragTrap.hpp"

int main(){
	FragTrap Fuzzy("Fuzzy");
	FragTrap unknown;

	Fuzzy.attack(unknown);
	Fuzzy.attack(unknown);
	Fuzzy.highFivesGuys();

	ClapTrap Clappy("Clappy");

	Clappy.attack(Fuzzy);
	Fuzzy.takeDamage(3);
	FragTrap Fizzy(Fuzzy);
	Fizzy.beRepaired(2);
	Fizzy.attack(Clappy);
	Fuzzy.attack(Clappy);
	Fizzy.highFivesGuys();

	Fizzy = unknown;
	Fizzy.attack(Fuzzy);
	Fizzy.highFivesGuys();
}
