#include "Karen.hpp"

int main(int argc, char **argv){
	if (argc != 2){
		std::cout	<< "Please enter one of the following log levels:\n"
					<< "  * DEBUG\n"
					<< "  * INFO\n"
					<< "  * WARNING\n"
					<< "  * ERROR\n";
		return (1);
	}
	Karen karen;
	karen.complain(argv[1]);
}
