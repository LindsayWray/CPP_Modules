#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


void	presidentForm(Bureaucrat& buro){

	PresidentialPardonForm Pardon("Mojo Jojo");
	std::cout << Pardon << std::endl;
	buro.signForm(Pardon);
	buro.executeForm(Pardon);
}

void	robotomyForm(Bureaucrat& buro){
	RobotomyRequestForm Robotomize("TotallyNotARobot");
	std::cout << Robotomize << std::endl;
	buro.signForm(Robotomize);
	buro.executeForm(Robotomize);
}

void	shrubberyForm(Bureaucrat& buro){
	ShrubberyCreationForm shrubbery("X-masTree");
	std::cout << shrubbery << std::endl;
	buro.signForm(shrubbery);
	buro.executeForm(shrubbery);
}

int main(){
	try{
		Bureaucrat lowlyBuro("lowlyBuro", 140);
		std::cout << lowlyBuro << std::endl;
		Bureaucrat highTierBuro("highTierBuro", 2);
		std::cout << highTierBuro << std::endl;

		std::cout << "\n *Try to execute PresidentForm with too low graded bureaucrat : * \n";
		presidentForm(lowlyBuro);
		std::cout << "\n *Try to execute PresidentForm with high tier bureaucrat : * \n";
		presidentForm(highTierBuro);

		std::cout << "\n *Try to execute RobotomyForm with too low graded bureaucrat : * \n";
		robotomyForm(lowlyBuro);
		std::cout << "\n *Try to execute RobotomyForm with high tier bureaucrat : * \n";
		robotomyForm(highTierBuro);

		std::cout << "\n *Try to execute ShrubberyForm with too low graded bureaucrat : * \n";
		shrubberyForm(lowlyBuro);
		std::cout << "\n *Try to execute ShrubberyForm with high tier bureaucrat : * \n";
		shrubberyForm(highTierBuro);
	}
	catch(Bureaucrat::GradeTooLowException& e){
		std::cerr << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException& e){
		std::cerr << e.what() << std::endl;
	}
}
