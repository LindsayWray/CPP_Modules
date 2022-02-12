#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(){
	Intern someRandomIntern;

	Form *robotomize;
	robotomize = someRandomIntern.makeForm("Robotomy Request", "Bender");
	delete robotomize;

	Form *shrubbery;
	shrubbery = someRandomIntern.makeForm("Shrubbery Creation", "X-mas Tree");
	delete shrubbery;

	Form* pardon;
	pardon = someRandomIntern.makeForm("Presidential Pardon", "every cat");
	Bureaucrat hermes("Hermes", 3);
	hermes.signForm(*pardon);
	hermes.executeForm(*pardon);
	delete pardon;

	Form* unknown;
	unknown = someRandomIntern.makeForm("blabla", "more bla");
	std::cout << unknown << std::endl;
	delete unknown;

}
