#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: ClapTrap("Anon_clap_name"), ScavTrap(), FragTrap(), _name("Anon"){
	std::cout << "DiamondTrap " << _name << " has been constructed\n";
	_hitPoints = FragTrap::_initHP;
	_energyPoints = ScavTrap::_initEnergy;
	_attackDamage = FragTrap::_initAttackDamage;
	_maxHP = FragTrap::_initHP;
	_maxEnergy = ScavTrap::_initEnergy;
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name  + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name){
	std::cout << "DiamondTrap " << _name << " has been constructed\n";
	_hitPoints = FragTrap::_initHP;
	_energyPoints = ScavTrap::_initEnergy;
	_attackDamage = FragTrap::_initAttackDamage;
	_maxHP = FragTrap::_initHP;
	_maxEnergy = ScavTrap::_initEnergy;
}

DiamondTrap::DiamondTrap(DiamondTrap const& original)
	: ClapTrap(original), ScavTrap(original), FragTrap(original), _name(original._name){
	std::cout << "DiamondTrap " << original._name << " has spawned an identical clone\n";
}

DiamondTrap::~DiamondTrap(void){
	std::cout << "DiamondTrap " << _name << " has been destroyed\n";
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const& original){
	std::cout << "DiamondTrap " << original._name << " has assimilated " << _name << std::endl;
	if(this == &original)
		return(*this);
	_name = original._name;
	ClapTrap::_name = original.ClapTrap::_name;
	_hitPoints = original._hitPoints;
	_energyPoints = original._energyPoints;
	_attackDamage = original._attackDamage;
	_maxHP = original._maxHP;
	_maxEnergy = original._maxEnergy;
	return *this;
}

void DiamondTrap::whoAmI(void){
	std::cout	<< "This is DiamondTrap: "
				<< _name
				<< ", AKA: "
				<< ClapTrap::_name
				<< std::endl;

}
