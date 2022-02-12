#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(DEFAULT_GRADE){
	std::cout << "Bureaucrat has been constructed\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade){
	std::cout << "Bureaucrat " << _name << " has been constructed\n";
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
}

Bureaucrat::Bureaucrat(Bureaucrat const& original) : _name(original._name), _grade(original._grade){
	std::cout << "Bureaucrat " << _name << " has been copy-constructed\n";
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat " << _name << " has been destructed\n";
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& original){ //maintains own name
	if (this == &original)
		return *this;
	_grade = original._grade;
	return *this;
}

std::string const	Bureaucrat::getName() const{
	return _name;
}

int		Bureaucrat::getGrade() const{
	return _grade;
}

void	Bureaucrat::improveGrade(){
	if (this->getGrade() == 1)
		throw (Bureaucrat::GradeTooHighException());
	_grade--;
}

void	Bureaucrat::diminishGrade(){
	if (this->getGrade() == 150)
		throw (Bureaucrat::GradeTooLowException());
	_grade++;
}

void	Bureaucrat::signForm(Form& form){
	try{
		form.beSigned(*this);
	}
	catch(Form::GradeTooLowException& e){
		std::cout << "Grade too low" << std::endl;
	}
	catch(Form::FormAlreadySignedException& e){
		std::cout << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(Form const& form) const{
	try{
		form.execute(*this);
		std::cout << _name << " has successfully executed " << form.getName() << std::endl;
	}
	catch(Form::FormNotSignedException& e){
		std::cout << e.what() << std::endl;
	}
	catch(Form::GradeTooLowForExecException& e){
		std::cout << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& bureaucrat){
	stream	<< "Bureaucrat "
			<< bureaucrat.getName()
			<< " has grade "
			<< bureaucrat.getGrade();
	return stream;
}
