#include "Intern.hpp"

Intern::Intern(){
	std::cout << "An Intern has been constructed\n";
	_forms_log[0].form = "Presidential Pardon";
	_forms_log[0].func_ptr = &Intern::writePresidentialPardon;
	_forms_log[1].form = "Robotomy Request";
	_forms_log[1].func_ptr = &Intern::writeRobotomy;
	_forms_log[2].form = "Shrubbery Creation";
	_forms_log[2].func_ptr = &Intern::writeShrubberyCreation;
}

Intern::Intern(Intern const&){
	std::cout << "An Intern has been copy-constructed\n";
}

Intern::~Intern(){
	std::cout << "An Intern has been destructed\n";
}

Intern&	Intern::operator=(Intern const&){ //nothing to copy
	return *this;
}

Form*	Intern::writePresidentialPardon(std::string target){
	return new PresidentialPardonForm(target);
}

Form*	Intern::writeRobotomy(std::string target){
	return new RobotomyRequestForm(target);
}

Form*	Intern::writeShrubberyCreation(std::string target){
	return new ShrubberyCreationForm(target);
}

Form*	Intern::makeForm(std::string form, std::string target) const{
	for(int i = 0; i < 3; i++){
		if (form == _forms_log[i].form)
			return (*_forms_log[i].func_ptr)(target);	//dereference the func_ptr as a whole, then call the function in question
	}
	std::cerr << "Requested form " << form << " is not known\n";
	return NULL; 
}
