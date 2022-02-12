#include "Brain.hpp"

Brain::Brain(void){
	std::cout << "Brain has been developed\n";
}

Brain::Brain(Brain const& original){
	std::cout << "A copy brain has been developed\n";
	for(int i = 0; i < 100; i++){
		_ideas[i] = original.getIdeas()[i];
	}
}

Brain::~Brain(void){
	std::cout << "Brain has checked out\n";
}

Brain& Brain::operator=(Brain const& original){
	if (this == &original)
		return (*this);
	for(int i = 0; i < 100; i++){
		_ideas[i] = original.getIdeas()[i];
	}
	return *this;
}

std::string const*	Brain::getIdeas() const{
	return _ideas;
}
