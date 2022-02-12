#include "Bureaucrat.hpp"
#include "Form.hpp"

void	try_form99(){

	std::cout << "\n *Try to construct form99 with wrong input grade: * \n";
	try{
		Form Form99("Form99", 999, 33);
		std::cout << Form99.getName() << std::endl;
		std::cout << Form99.getSignReq() << std::endl;
		std::cout << Form99 << std::endl;
	}
	// catch(std::exception& e){
	// 	std::cout << e.what() << std::endl;
	// }
	catch(Form::GradeTooLowException& e){
		std::cout << e.what() << std::endl;
	}
	catch(Form::GradeTooHighException& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n *Try to construct Form99 with acceptable input grade: * \n";
	try{
		Form Form99("Form99", 99, 33);
		std::cout << "Name: " << Form99.getName() << std::endl;
		std::cout << "Sign grade requirement: " << Form99.getSignReq() << std::endl;
		std::cout << "Exec grade requirement: " << Form99.getExecReq() << std::endl;
		std::cout << Form99 << std::endl;
	}
	catch(Form::GradeTooLowException& e){
		std::cout << e.what() << std::endl;
	}
	catch(Form::GradeTooHighException& e){
		std::cout << e.what() << std::endl;
	}
}

void	classifiedForm(){
	std::cout << "\n *Get this highly classified form signed* \n";
	try{
		Form classified("classified", 1, 1);
		std::cout << classified << std::endl;
		Bureaucrat lowlyBuro("lowlyBuro", 120);
		std::cout << lowlyBuro << std::endl;
		classified.beSigned(lowlyBuro);
	}
	catch(Form::GradeTooLowException& e){
		std::cout << e.what() << std::endl;
	}
	catch(Form::GradeTooHighException& e){
		std::cout << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException& e){
		std::cout << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException& e){
		std::cout << e.what() << std::endl;
	}
	catch(Form::FormAlreadySignedException& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n *Get this highly classified form signed* \n";
	try{
		Form classified("classified", 1, 1);
		std::cout << classified << std::endl;
		Bureaucrat highTierBuro("highTierBuro", 1);
		std::cout << highTierBuro << std::endl;
		classified.beSigned(highTierBuro);
		std::cout << classified << std::endl;
		classified.beSigned(highTierBuro); //try signing an already signed form
	}
	catch(Form::GradeTooLowException& e){
		std::cout << e.what() << std::endl;
	}
	catch(Form::GradeTooHighException& e){
		std::cout << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException& e){
		std::cout << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException& e){
		std::cout << e.what() << std::endl;
	}
	catch(Form::FormAlreadySignedException& e){
		std::cout << e.what() << std::endl;
	}
}

void	giveBureaucratForms(){
	std::cout << "\n *Give this bureaucrat forms to sign* \n";
	try{
		Bureaucrat Hermes("Hermes", 20);
		Form lanPartyForm("lanPartyForm", 100, 5);
		Hermes.signForm(lanPartyForm);
		Form crossTheStreetForm("crossTheStreetForm", 1, 1);
		Hermes.signForm(crossTheStreetForm);
		Form catAdoptionForm("catAdoptionForm", 25, 5);
		Hermes.signForm(catAdoptionForm);
		Hermes.signForm(catAdoptionForm); //try signing an already signed form
	}
	catch(Form::GradeTooLowException& e){
		std::cout << e.what() << std::endl;
	}
	catch(Form::GradeTooHighException& e){
		std::cout << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException& e){
		std::cout << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException& e){
		std::cout << e.what() << std::endl;
	}
}

int main(){
	try_form99();
	classifiedForm();
	giveBureaucratForms();
}
