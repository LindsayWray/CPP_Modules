#include "Karen.hpp"

Karen::Karen(void){
	_log_table[0].level = "DEBUG";
	_log_table[0].func_ptr = &Karen::debug;
	_log_table[1].level = "INFO";
	_log_table[1].func_ptr = &Karen::info;
	_log_table[2].level = "WARNING";
	_log_table[2].func_ptr = &Karen::warning;
	_log_table[3].level = "ERROR";
	_log_table[3].func_ptr = &Karen::error;
}

Karen::~Karen(void){
}

void Karen::complain(std::string level){
	for(int i = 0; i < 4; i++){
		if (level == _log_table[i].level)
			(this->*_log_table[i].func_ptr)();	//dereference the func_ptr as a whole, then call the function in question
	}
}

void Karen::debug( void ){
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!\n";
}

void Karen::info( void ){
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!\n";
}

void Karen::warning( void ){
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month.\n";
}

void Karen::error( void ){
	std::cout << "This is unacceptable, I want to speak to the manager now.\n";
}

