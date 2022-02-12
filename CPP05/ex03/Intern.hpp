#ifndef INTERN_HPP
# define INTERN_HPP
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern{
private:
	typedef Form* (*t_func)(std::string); // t_func is an alias for a ptr to a function

	typedef struct s_forms{
		std::string	form;
		t_func		func_ptr;
	} t_forms;

	t_forms	_forms_log[3];

	static Form*	writePresidentialPardon(std::string target); //not const since its not bound to a particular instance (cause static duh)
	static Form*	writeRobotomy(std::string target);
	static Form*	writeShrubberyCreation(std::string target);
public:
	Intern();
	Intern(Intern const&);
	~Intern();

	Intern&	operator=(Intern const& original);
	Form*	makeForm(std::string nameForm, std::string target) const;
};

#endif
