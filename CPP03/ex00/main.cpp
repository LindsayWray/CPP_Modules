#include "ClapTrap.hpp"

int main(){
	ClapTrap Lola("Lola");
	Lola.attack("her fears");

	ClapTrap unknown;

	ClapTrap LolaCopy(Lola); //copy also takes over _name 
	LolaCopy.attack(Lola);
	Lola.attack(unknown);

	Lola.beRepaired(1);
	unknown.beRepaired(3);

	ClapTrap Billy("Billy");

	Billy.takeDamage(3);
	Billy.takeDamage(10);
	Billy.beRepaired(100);
	Lola.attack(Billy);

	unknown = Billy; //now there are two Billy's!!
	unknown.beRepaired(0);
	Billy.beRepaired(0);
}
