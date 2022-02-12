#include <iostream>
#include <string>

int main(){
	std::string msg = "HI THIS IS BRAIN";
	
	std::string *stringPTR = &msg;
	std::string& stringREF = msg;

	std::cout << "Display memory address     : " << &msg << std::endl;
	std::cout << "Memory address by pointer  : " << stringPTR << std::endl;
	std::cout << "Memory address by reference: " << &stringREF << std::endl;
	std::cout << "Display string by pointer  : " << *stringPTR << std::endl;
	std::cout << "Display string by reference: " << stringREF << std::endl;
}
