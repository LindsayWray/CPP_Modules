#include "ScavTrap.hpp"

int main(){
	ScavTrap Pamela("Pamela");
	ScavTrap Pamelo(Pamela); //copy of pamela

	Pamelo.attack(Pamela); //Scavtrap attack func
	Pamelo.attack(Pamela);
	Pamelo.attack(Pamela);
	Pamelo.attack(Pamela);
	Pamelo.attack(Pamela);
	Pamelo.attack(Pamela);
	Pamelo.attack(Pamela);

	ScavTrap unknown;
	unknown.guardGate();
	unknown.guardGate();
	ClapTrap Billy("Billy");
	Billy.attack(unknown); //claptrap attack func

	unknown = Pamelo; //assignment test
	unknown.beRepaired(2); // 50 - 7 attacks + 2 repair = 45
}
