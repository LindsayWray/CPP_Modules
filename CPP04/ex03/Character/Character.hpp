#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"

class Character : public ICharacter{
private:
	AMateria			*_materias[4];
	std::string			_name;
public:
	Character();
	Character(std::string name);
	Character(Character const& original);
	virtual ~Character();

	Character&			operator=(Character const& original);
	std::string const&	getName() const;
	void 				equip(AMateria* m);
	void				unequip(int index);
	void				use(int index, ICharacter& target);
};

#endif
