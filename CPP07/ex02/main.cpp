#include "Array.hpp"

void	subjectTests(){
	std::cout << "\n----   Subject tests:  ---- \n";
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];

	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++){
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		for (int i = 0; i < MAX_VAL; i++){
			if (mirror[i] != tmp[i]){
				std::cerr << "didn't save the same value!!" << std::endl;
				return ;
			}
		}
		Array<int> test(tmp);
		for (int i = 0; i < MAX_VAL; i++){
			if (mirror[i] != test[i]){
				std::cerr << "didn't save the same value!!" << std::endl;
				return ;
			}
		}
	}

	for (int i = 0; i < MAX_VAL; i++){
		if (mirror[i] != numbers[i]){
			std::cerr << "didn't save the same value!!" << std::endl;
			return ;
		}
	}
	try{
		numbers[-2] = 0;
	}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
	}
	try{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++){
		numbers[i] = rand();
	}
	delete [] mirror;
}

void	stringTests(){
	std::cout << "\n----   String tests:  ---- \n";
	Array<std::string> strings(8);
	std::cout << "Elements are instantiated by default: \n";
	for(int i = 0; i < 8; i++){
		std::cout << "-> " << strings[i] <<  "<- empty string" << std::endl;
	}

	std::string str = "stringA";
	for(int i = 0; i < 8; i++){
		strings[i] = str;
		str[6]++;
		//std::cout << strings[i] << std::endl;
	}

	std::cout << "\nPrint string on 4th index: " << strings[4] << std::endl;
	std::cout << "Print size of this array: " << strings.size() << std::endl;

	
	std::cout << "\n----   Copy constructor tests:  ---- ";
	Array<std::string> copy(strings);
	copy[4] = "stringCopy";
	copy[7] = "imposterString";
	std::cout << "\nOriginal string on 4th index: " << strings[4] << std::endl;
	std::cout << "Altered copy string on 4th index: " << copy[4] << std::endl;
	std::cout << "\nOriginal string on 7th index: " << strings[7] << std::endl;
	std::cout << "Altered copy string on 7th index: " << copy[7] << std::endl;

	std::cout << "\n----   Assignement operator tests:  ---- ";
	Array<std::string>  dup = copy;
	std::cout << "\nOriginal string on 4th index: " << strings[4] << std::endl;
	std::cout << "Copy string on 4th index: " << copy[4] << std::endl;
	std::cout << "Duplicated string on 4th index: " << dup[4] << std::endl;
	dup[4] = "stringX";
	std::cout << "\nOriginal string on 4th index: " << strings[4] << std::endl;
	std::cout << "Copy string on 4th index: " << copy[4] << std::endl;
	std::cout << "Altered duplicated string on 4th index: " << dup[4] << std::endl;
}

void	defaultConstr(){
	std::cout << "\n----   Default constructor tests:  ---- \n";
	Array<int> empty; //needs a typename to instantiate
	std::cout << "size: " << empty.size() << std::endl;
	try{
		std::cout << empty[0] << std::endl;
	}
	catch(const Array<int>::IndexOutofBoundsException& e){
		std::cerr << e.what() << std::endl;
	}
	try{
		empty[0] = 3000;
	}
	catch(const Array<int>::IndexOutofBoundsException& e){
		std::cerr << e.what() << std::endl;
	}
}

int main(int, char**)
{
	subjectTests();
	stringTests();
	defaultConstr();
}
