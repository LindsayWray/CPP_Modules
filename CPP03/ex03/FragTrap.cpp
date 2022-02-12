#include "FragTrap.hpp"

FragTrap::FragTrap(void)
	: ClapTrap(){
	_hitPoints = _initHP;
	_energyPoints = _initEnergy;
	_attackDamage = _initAttackDamage;
	_maxHP = _initHP;
	_maxEnergy = _initEnergy;
	std::cout << "FragTrap " << _name << " has been constructed\n";
}

FragTrap::FragTrap(std::string name)
	: ClapTrap(name){
	_hitPoints = _initHP;
	_energyPoints = _initEnergy;
	_attackDamage = _initAttackDamage;
	_maxHP = _initHP;
	_maxEnergy = _initEnergy;
	std::cout << "FragTrap " << _name << " has been constructed\n";
}

FragTrap::FragTrap(FragTrap const& original)
	: ClapTrap(original){
	std::cout << "FragTrap " << original._name << " has spawned an identical clone\n";
}

FragTrap::~FragTrap(void){
	std::cout << "FragTrap " << _name << " has been destroyed\n";
}

FragTrap& FragTrap::operator=(FragTrap const& original){
	std::cout << "FragTrap " << original._name << " has assimilated " << _name << std::endl;
	if(this == &original)
		return(*this);
	_name = original._name;
	_hitPoints = original._hitPoints;
	_energyPoints = original._energyPoints;
	_attackDamage = original._attackDamage;
	_maxHP = original._maxHP;
	_maxEnergy = original._maxEnergy;
	return *this;
}

void FragTrap::highFivesGuys(void){
	std::cout << "Fragtrap " << _name << " would like a high five!\n";
}
