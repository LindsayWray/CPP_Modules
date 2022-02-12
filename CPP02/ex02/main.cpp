#include "Fixed.hpp"

int main(void){
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	Fixed const c(Fixed(3.4f) + Fixed(6.2f));
	std::cout << std::endl << "+ operation: " << c << std::endl;
	Fixed const d(Fixed(4) - Fixed(1.3f));
	std::cout << "- operation: " << d << std::endl;
	Fixed e(Fixed(91) / Fixed(3));
	std::cout << "/ operation: " << e << std::endl;
	std::cout << "<= operation: " << (c <= d) << std::endl;

	Fixed copy_e(e);
	std::cout << "copied instince " << e << " copy_e " << copy_e << std::endl;
	std::cout << "== operation: " << (e == copy_e) << std::endl;
	std::cout << "!= operation: " << (e != copy_e) << std::endl;
	std::cout << "min operation: " << Fixed::min(c, e) << std::endl;
	std::cout << "min operation: " << Fixed::min((Fixed const)e, d) << std::endl;

	return 0;
}
