#include "DiamondTrap.hpp"

int main(){
	DiamondTrap Gemmy("Gemmy");

	Gemmy.attack("Spades");		//does same damage as frag  ||   uses attack func from scav
	Gemmy.takeDamage(5);		//hp same as frag
	Gemmy.beRepaired(0);		// energy lvl is set same as scav
	Gemmy.highFivesGuys();		//frag specific func
	Gemmy.guardGate();			//scav specific func
	Gemmy.whoAmI();

	std::cout << std::endl;

	DiamondTrap unknown;
	unknown.whoAmI();
	unknown.guardGate();
	DiamondTrap Ruby(Gemmy);
	Ruby.whoAmI();
	Ruby.attack(unknown);
	Ruby.highFivesGuys();
	unknown = Gemmy;
	unknown.whoAmI();

	std::cout << std::endl;

	ScavTrap Scavy("Scavy");
	FragTrap Fragy("Fragy");
	ClapTrap Clapy("Clapy");

	Clapy = Gemmy; //Gemmy is also a claptrap
	Clapy.attack(Fragy);
	Clapy.takeDamage(20);
	Clapy.beRepaired(2);
	Fragy.attack(Scavy);
	Scavy.beRepaired(4);
}
