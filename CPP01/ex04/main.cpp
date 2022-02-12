#include "Replace.hpp"

int main(int argc, char **argv){

	if (argc != 4){
		std::cerr	<< "Incorrect program usage\n"
					<< "Enter filename, a string to find and a replacement string\n";
		return 1;
	}
	if (!*argv[1] || !*argv[2] || !*argv[3]){
		std::cerr	<< "This program does not accept empty input\n";
		return 1;
	}

	Replace replace(argv[1]);
	replace.replace_string(argv[2], argv[3]);	
}
