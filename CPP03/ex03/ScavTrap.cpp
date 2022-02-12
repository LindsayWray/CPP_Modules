#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
	: ClapTrap(), _isGuarding(false){
	_hitPoints = _initHP;
	_energyPoints = _initEnergy;
	_attackDamage = _initAttackDamage;
	_maxHP = _initHP;
	_maxEnergy = _initEnergy;
	std::cout << "ScavTrap " << _name << " has been constructed\n";
}

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name), _isGuarding(false){
	_hitPoints = _initHP;
	_energyPoints = _initEnergy;
	_attackDamage = _initAttackDamage;
	_maxHP = _initHP;
	_maxEnergy = _initEnergy;
	std::cout << "ScavTrap " << _name << " has been constructed\n";
}

ScavTrap::ScavTrap(ScavTrap const& original)
	: ClapTrap(original), _isGuarding(original._isGuarding){
	std::cout << "ScavTrap " << original._name << " has spawned an identical clone\n";
}

ScavTrap::~ScavTrap(void){
	std::cout << "ScavTrap " << _name << " has been destroyed\n";
}

ScavTrap& ScavTrap::operator=(ScavTrap const& original){
	std::cout << "ScavTrap " << original._name << " has assimilated " << _name << std::endl;
	if(this == &original)
		return(*this);
	_name = original._name;
	_hitPoints = original._hitPoints;
	_energyPoints = original._energyPoints;
	_attackDamage = original._attackDamage;
	_isGuarding = original._isGuarding;
	_maxHP = original._maxHP;
	_maxEnergy = original._maxEnergy;
	return *this;
}

void ScavTrap::guardGate(){
	if (_isGuarding)
		std::cout << "ScavTrap " << _name << " is still on gate keeping duty\n";
	else
		std::cout << "ScavTrap " << _name << " has entered gate keeper mode\n";
	_isGuarding = true;
}

void ScavTrap::attack(std::string const& target){
	if(_energyPoints == 0){
		std::cout << "ScavTrap " << _name << " doesn't have the energy to attack 💤\n";
	}
	_energyPoints--;
	std::cout << "ScavTrap "<< _name << " savagely attacks " << target << " and inflicts " << _attackDamage << " damage! 💥\n";
}

void ScavTrap::attack(ClapTrap& target){ // overload to also include the attacked claptrap
	attack(target.get_name());
	target.takeDamage(_attackDamage);
}
