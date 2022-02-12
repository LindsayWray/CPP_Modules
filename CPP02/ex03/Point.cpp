#include "Point.hpp"

Point::Point(void){
}

Point::~Point(void){
}

Point::Point(const Point& original)
	: x(original.x), y(original.y){
}

Point::Point(const float x, const float y)
	: x(x), y(y){
}

Point& Point::operator=(Point const& original){
	(void) original;
	return(*this); //a const value (x and y in this case) should not be able to get a different value
}

Fixed const& Point::getX(void) const{
	return this->x;
}

Fixed const& Point::getY(void) const{
	return this->y;
}
