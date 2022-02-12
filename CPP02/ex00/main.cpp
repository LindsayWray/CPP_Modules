#include "Fixed.hpp"

int main(void){
	Fixed a;
	//a.setRawBits(32);
	Fixed b(a);
	Fixed c;
	c = b; // the object c calls the function operater= with b as argument

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}
