#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: Form("Shrubbery Creation", 145, 137){
	std::cout << getName() << " has been constructed\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: Form("Shrubbery Creation", 145, 137){
	std::cout << getName() << " has been constructed\n";
	setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& original)
	: Form(original.getName(), original.getSignReq(), original.getExecReq()){
	std::cout << getName() << " has been copy-constructed\n";
	setTarget(original.getTarget());
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout << getName() << " has been destructed\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& original){
	setSignReq(original.getSignReq());
	setExecReq(original.getExecReq());
	setTarget(original.getTarget());
	return *this;
}

void	ShrubberyCreationForm::formExecution(std::string target) const{
	std::ofstream shrub_file(target + "_shrubbery", std::ios_base::trunc);
	if (!shrub_file.is_open()) {
		std::cerr << "Could not open file\n";
		return;
	}
	shrub_file	<< "         *\n"
				<< "        /|\\\n"
				<< "       /*|O\\\n"
				<< "      /*/|\\*\\\n"
				<< "     /X/O|*\\X\\\n"
				<< "    /*/X/|\\X\\*\\\n"
				<< "   /O/*/X|*\\O\\X\\\n"
				<< "  /*/O/X/|\\X\\O\\*\\\n"
				<< " /X/O/*/X|O\\X\\*\\O\\\n"
				<< "/O/X/*/O/|\\X\\*\\O\\X\\\n"
				<< "        |X|\n"
				<< "        |X|";
	std::cout << "A Christmas Tree has been setup\n";
}
