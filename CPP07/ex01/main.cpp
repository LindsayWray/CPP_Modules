#include "iter.hpp"

void	increaseInt(int value){
	value++;
	std::cout << value << "  ";
}

void	printString(std::string str){
	std::cout << str << std::endl;
}

void	floatSquared(float value){
	std::cout << value * value << std::endl; 
}

void	isPrime(int num){
	for(int i = 2; i <= num / 2; i++){
		if(num % i == 0) {
			std::cout << num << " is not a prime\n";
			return ;
		}
	}
	std::cout << num << " is a Prime\n";
}

void	convertChar(char value){
	std::cout << "\nconvert char:   '" << value << "'" << std:: endl;
	std::cout << "        int:    " << static_cast<int>(value) << std::endl;
	std::cout << std::fixed;
	std::cout << "        float:  " << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	std::cout << "        double: " << std::setprecision(1) << static_cast<double>(value) << std::endl;
}

int main(){

	std::cout << "\n- Increase every integer in the array -\n";
	int intArray[] = {1, 2, 3, 4, 5, 6, 7};
	iter(intArray, 7, increaseInt);

	std::cout << "\n\n- Print every string in the array -\n";
	std::string stringArray[] = {"	Hello", "	World", "	Hello", "	Universe"};
	iter(stringArray, 4, printString);

	std::cout << "\n\n- Floats to the power -\n";
	float floatArray[] = {7.19, 3, 1.777, 9.3};
	iter(floatArray, 4, floatSquared);

	std::cout << "\n\n- Check if it's a prime number -\n";
	int primeArray[] = {8, 17, 300, 101, 641};
	iter(primeArray, 5, isPrime);

	std::cout << "\n\n- Convert char to int, float and double -";
	char charArray[] = {'r', 'P', 'z'};
	iter(charArray, 3, convertChar);

	std::cout << "\n\n- Print int values through template function - \n";
	iter(intArray, 7, printValue);

	std::cout << "\n\n- Print string values through template function - \n";
	std::string strArray[] = {"string", "moreString", "even more"};
	iter(strArray, 3, printValue);

	std::cout << std::endl;
}


