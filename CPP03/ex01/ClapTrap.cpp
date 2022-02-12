#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	: _name("Anon"), _hitPoints(10), _energyPoints(10), _attackDamage(0), _maxHP(10), _maxEnergy(10){
	std::cout << "ClapTrap " << _name << " has been constructed\n";
}

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0), _maxHP(10), _maxEnergy(10){
	std::cout << "ClapTrap " << _name << " has been constructed\n";
}

ClapTrap::ClapTrap(ClapTrap const& original)
	: _name(original._name), _hitPoints(original._hitPoints), _energyPoints(original._energyPoints),
		_attackDamage(original._attackDamage), _maxHP(original._maxHP), _maxEnergy(original._maxEnergy){
	std::cout << "ClapTrap " << original._name << " has spawned an identical clone\n";
}

ClapTrap::~ClapTrap(void){
	std::cout << "ClapTrap " << _name << " has been destroyed\n";
}

ClapTrap& ClapTrap::operator=(ClapTrap const& original){
	std::cout << "ClapTrap " << original._name << " has assimilated " << _name << std::endl;
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

void ClapTrap::attack(std::string const& target){
	if(_energyPoints == 0){
		std::cout << "ClapTrap " << _name << " doesn't have the energy to attack 💤\n";
		return ;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " savagely attacks " << target << " and inflicts " << _attackDamage << " damage! 💥\n";
}

void ClapTrap::attack(ClapTrap& target){ // overload to also include the attacked claptrap
	attack(target._name);
	target.takeDamage(_attackDamage);
}

void ClapTrap::takeDamage(unsigned int amount){
	if (_hitPoints < 0){
		std::cout << "ClapTrap " << _name << " is already demolished, give them some rest ⚰️\n";
		return ;
	}
	_hitPoints = _hitPoints - amount;
	if (_hitPoints < 0){
		std::cout << "ClapTrap " << _name << " has been brutally demolished 💀\n";
		return ;
	}
	std::cout << "ClapTrap " << _name << " has taken " << amount << " damage! 💥\n";
}

void ClapTrap::beRepaired(unsigned int amount){
	_hitPoints = _hitPoints + amount;
	if (_hitPoints >= _maxHP){
		_hitPoints = _maxHP;
		std::cout << "ClapTrap " << _name << "'s hp is fully maxed! 🦾\n";
	}
	else
		std::cout << "ClapTrap " << _name << "'s hp has been restored to " << _hitPoints << " ⬆\n";

	_energyPoints = _energyPoints + amount;
	if (_energyPoints >= _maxEnergy){
		_energyPoints = _maxEnergy;
		std::cout << "ClapTrap " << _name << "'s energy is fully maxed! 🔋\n";
		return ;
	}
	std::cout << "ClapTrap " << _name << "'s energy has been restored to " << _energyPoints << " ⬆\n";
}

std::string ClapTrap::getName() const{
	return _name;
}
