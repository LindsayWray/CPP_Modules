#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(void){
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPointValue = 0;
}


Fixed::Fixed(const int value){  //constructor that takes an int as param
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = value << _fractionalBits;  //bitshifts x places to the left, where x is the amount of decimal bits
}

Fixed::Fixed(const float value){  //constructor that takes an float as param
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = std::roundf(value * (1 << _fractionalBits)); //multiply with the bitplace that seperates the decimal
}

Fixed::Fixed(const Fixed& original){  // copy constructor
	std::cout << "Copy constructor called" << std::endl;
	this->_fixedPointValue = original.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& original){
	std::cout << "Assignation operator called" << std::endl;
	if(this == &original)
		return(*this);
	this->_fixedPointValue = original.getRawBits();
	return *this;
}

Fixed::~Fixed(void){
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const{
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw){
	this->_fixedPointValue = raw;
}

int Fixed::toInt(void) const{
	int value = this->_fixedPointValue >> _fractionalBits;
	return value;
}

float Fixed::toFloat(void) const{
	float value = (float)_fixedPointValue / (1 << _fractionalBits);
	return value;
}

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed){
	float value = fixed.toFloat();
	stream << value;
	return stream;
}
