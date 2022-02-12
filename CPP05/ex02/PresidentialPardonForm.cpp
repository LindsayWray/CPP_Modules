#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: Form("Presidential Pardon", 25, 5){
	std::cout << getName() << " has been constructed\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: Form("Presidential Pardon", 25, 5){
	std::cout << getName() << " has been constructed\n";
	setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& original)
	: Form(original.getName(), original.getSignReq(), original.getExecReq()){
	std::cout << getName() << " has been copy-constructed\n";
	setTarget(original.getTarget());
}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << getName() << " has been destructed\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& original){
	setSignReq(original.getSignReq());
	setExecReq(original.getExecReq());
	setTarget(original.getTarget());
	return *this;
}

void	PresidentialPardonForm::formExecution(std::string target) const{
	std::cout << target << " has been pardoned by Zafod Beeblebrox\n";
}
