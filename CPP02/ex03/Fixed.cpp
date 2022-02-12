#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

//CONSTRUCTORS
Fixed::Fixed(void){
	this->_fixedPointValue = 0;
}

Fixed::Fixed(const int value){
	this->_fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float value){
	this->_fixedPointValue = std::roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& original){
	this->_fixedPointValue = original.getRawBits();
}


//DESTRUCTOR
Fixed::~Fixed(void){
}


//GETTERS AND SETTERS
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


//OPERATOR OVERLOADS
Fixed& Fixed::operator=(const Fixed& original){
	if(this == &original)
		return(*this);
	this->_fixedPointValue = original.getRawBits();
	return *this;
}

bool Fixed::operator>(Fixed const& rhs) const{
	return(this->getRawBits() > rhs.getRawBits());
}

bool Fixed::operator<(Fixed const& rhs) const{
	return(this->getRawBits() < rhs.getRawBits());
}

bool Fixed::operator>=(Fixed const& rhs) const{
	return(this->getRawBits() >= rhs.getRawBits());
}
bool Fixed::operator<=(Fixed const& rhs) const{
	return(this->getRawBits() <= rhs.getRawBits());
}

bool Fixed::operator==(Fixed const& rhs) const{
	return(this->getRawBits() == rhs.getRawBits());
}

bool Fixed::operator!=(Fixed const& rhs) const{
	return(this->getRawBits() != rhs.getRawBits());
}

Fixed Fixed::operator+(Fixed const& rhs) const{
	return (Fixed(this->toFloat() + rhs.toFloat())); //creates and returns a new Fixed instance containing the addition result 
}

Fixed Fixed::operator-(Fixed const& rhs) const{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(Fixed const& rhs) const{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(Fixed const& rhs) const{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed& Fixed::operator++(){
	this->_fixedPointValue++;
	return *this;
}

Fixed Fixed::operator++(int){
	Fixed copy(*this);
	this->_fixedPointValue++;
	return copy;
}

Fixed& Fixed::operator--(){
	this->_fixedPointValue--;
	return *this;
}

Fixed Fixed::operator--(int){
	Fixed copy(*this);
	this->_fixedPointValue--;
	return copy;
}

Fixed const& Fixed::max(Fixed const& value1, Fixed const& value2){
	if (value1 > value2) //make use of my previously made operator overload
		return value1;
	return value2;
}

Fixed& Fixed::max(Fixed& value1, Fixed& value2){
	if (value1 > value2)
		return value1;
	return value2;
}

Fixed const& Fixed::min(Fixed const& value1, Fixed const& value2){
	if (value1 < value2)
		return value1;
	return value2;
}

Fixed& Fixed::min(Fixed& value1, Fixed& value2){
	if (value1 < value2)
		return value1;
	return value2;
}

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed){
	float value = fixed.toFloat();
	stream << value;
	return stream;
}
