#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(void){
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPointValue = 0;
}

/* this is the copy constructor, it will create a new instance for you,
	the same way a default constructor does */
Fixed::Fixed(const Fixed& original){
	std::cout << "Copy constructor called" << std::endl;
	this->_fixedPointValue = original.getRawBits();
}
/* the assignation operator overload function. */
Fixed& Fixed::operator=(const Fixed& original){
	std::cout << "Assignation operator called" << std::endl;
	if(this == &original)  // assignment operator is expected to perform no action on self-assignment
		return(*this);		//https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#c62-make-copy-assignment-safe-for-self-assignment
	this->_fixedPointValue = original.getRawBits();
	return *this;
}

Fixed::~Fixed(void){
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw){
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}
