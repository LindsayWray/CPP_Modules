#include "Form.hpp"

Form::Form(){}

Form::Form(std::string formName, int signReq, int execReq)
	: _formName(formName), _signReq(signReq), _execReq(execReq), _signed(false){
	std::cout << "Form " << _formName << " has been constructed\n";
	if (signReq < 1 || execReq < 1)
		throw (Form::GradeTooHighException());
	if (signReq > 150 || execReq > 150)
		throw (Form::GradeTooLowException());
}

Form::Form(Form const& original)
	: _formName(original._formName), _signReq(original._signReq), _execReq(original._execReq), _signed(original._signed){
	std::cout << "Form " << _formName << " has been copy-constructed\n";
}

Form::~Form(){
	std::cout << "Form " << _formName << " has been destructed\n";
}

Form&	Form::operator=(Form const& original){
	_signReq = original._signReq;
	_execReq = original._execReq;
	_signed = original._signed;
	return *this;
}

std::string	const	Form::getName() const{
	return _formName;
}

int	Form::getSignReq() const{
	return _signReq;
}

void	Form::setSignReq(int signReq){
	_signReq = signReq;
}

int	Form::getExecReq() const{
	return _execReq;
}

void	Form::setExecReq(int execReq){
	_execReq = execReq;
}

bool		Form::getSigned() const{
	return _signed;
}

void	Form::beSigned(Bureaucrat const& bureaucrat){
	if (bureaucrat.getGrade() > this->getSignReq()){
		std::cout << "Bureaucrat " << bureaucrat.getName() << " not authorized to sign " << _formName << std::endl;
		throw (Form::GradeTooLowException());
	}
	if (_signed)
		throw (Form::FormAlreadySignedException());
	_signed = true;
	std::cout	<< bureaucrat.getName()
				<< " has signed "
				<< this->getName()
				<< std::endl;
}

std::string	Form::getTarget() const{
	return _target;
}

void	Form::setTarget(std::string target){
	_target = target;
}

void	Form::execute(Bureaucrat const & executor) const{
	if (!getSigned())
		throw (Form::FormNotSignedException());
	if (executor.getGrade() > getExecReq())
		throw (Form::GradeTooLowForExecException());
	formExecution(getTarget());
}

std::ostream& operator<<(std::ostream& stream, const Form& form){
	stream	<< form.getName()
			<< " requires at least grade "
			<< form.getSignReq()
			<< " to be signed. And at least grade "
			<< form.getExecReq()
			<< " to be executed. It's current status is: ";
	if (form.getSigned())
		stream << "signed";
	else
		stream << "not signed";
	return stream;
}
