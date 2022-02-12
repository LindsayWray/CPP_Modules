#include <iostream>
#include <string>


int main(int argc, char **argv){
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	std::string input;
	for (int i = 1; i < argc; i++){
		input = argv[i];
		for(unsigned long j = 0; j < input.length(); j++){
			char letter = std::toupper(input[j]);
			std::cout << letter;
		}
	}
	std::cout << std::endl;
	return (0);
}