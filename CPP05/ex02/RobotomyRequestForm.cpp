#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: Form("Robotomy Request", 72, 45){
	std::cout << getName() << " has been constructed\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: Form("Robotomy Request", 72, 45){
	std::cout << getName() << " has been constructed\n";
	setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& original)
	: Form(original.getName(), original.getSignReq(), original.getExecReq()){
	std::cout << getName() << " has been copy-constructed\n";
	setTarget(original.getTarget());
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << getName() << " has been destructed\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& original){
	setSignReq(original.getSignReq());
	setExecReq(original.getExecReq());
	setTarget(original.getTarget());
	return *this;
}

void	RobotomyRequestForm::formExecution(std::string target) const{
	std::cout << " ***drilling noises....***\n	more drilling noises....*** \n";
	std::srand(std::time(NULL));
	if (std::rand() % 2)
		std::cout << target << " has been robotomized successfully\n";
	else
		std::cout << "The robotomization of " << target <<  " was unsuccessfull\n";
}
