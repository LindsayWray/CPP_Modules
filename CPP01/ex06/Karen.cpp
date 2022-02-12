#include "Karen.hpp"

Karen::Karen(void){
}

Karen::~Karen(void){
}

int	Karen::match_case(std::string level){
	if (level == "DEBUG")
		return (DEBUG);
	if (level == "INFO")
		return (INFO);
	if (level == "WARNING")
		return (WARNING);
	if (level == "ERROR")
		return (ERROR);
	else
		return (NO_LEVEL);
}

void Karen::complain(std::string level){
	int case_lvl = match_case(level); // switch needs an int
	switch(case_lvl){
		case NO_LEVEL:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
			break ;
		case DEBUG:
			Karen::debug();
		case INFO:
			Karen::info();
		case WARNING:
			Karen::warning();
		case ERROR:
			Karen::error();
	} 
}

void Karen::debug(void){
	std::cout	<< "[ DEBUG ]\n"
				<< "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!\n";
}

void Karen::info(void){
	std::cout	<< "[ INFO ]\n"
				<< "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!\n";
}

void Karen::warning(void){
	std::cout	<< "[ WARNING ]\n"
				<< "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month.\n";
}

void Karen::error(void){
	std::cout	<< "[ ERROR ]\n"
				<< "This is unacceptable, I want to speak to the manager now.\n";
}
