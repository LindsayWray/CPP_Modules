#include "Bureaucrat.hpp"

void	try_clippy(){

	std::cout << "\n *Try to construct Bureaucrat Clippy with wrong input grade: * \n";
	try{
		Bureaucrat Clippy("Clippy", 200);
		std::cout << "Name: " << Clippy.getName() << std::endl;
		std::cout << "Grade: " << Clippy.getGrade() << std::endl;
		std::cout << Clippy << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException& e){
		std::cout << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n *Try to construct Bureaucrat Clippy with acceptable input grade: * \n";
	try{
		Bureaucrat Clippy("Clippy", 120);
		std::cout << Clippy.getName() << std::endl;
		std::cout << Clippy.getGrade() << std::endl;
		std::cout << Clippy << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException& e){
		std::cout << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException& e){
		std::cout << e.what() << std::endl;
	}
}

void	hermes(){
	std::cout << "\n *Bureaucrat Hermes doing amazing: * \n";
	try{
		Bureaucrat Hermes("Hermes", 2);
		std::cout << Hermes << std::endl;
		Hermes.improveGrade();
		std::cout << Hermes << std::endl; //-> reached best possible grade
		Hermes.improveGrade();
		std::cout << Hermes << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException& e){
		std::cout << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n *Bureaucrat Hermes doing terribly: * \n";
	try{
		Bureaucrat Hermes("Hermes", 149);
		std::cout << Hermes << std::endl;
		Hermes.diminishGrade();
		std::cout << Hermes << std::endl; //-> reached worst possible grade
		Hermes.diminishGrade();
		std::cout << Hermes << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException& e){
		std::cout << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException& e){
		std::cout << e.what() << std::endl;
	}
}

int main(){
	try_clippy();
	hermes();
}
