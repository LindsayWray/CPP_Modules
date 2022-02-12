#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class Point{
public:

	Point(void);
	Point(const Point& original);
	Point(const float x, const float y);
	~Point(void);

	Point& operator=(Point const& original);
	Fixed const& getX(void) const;
	Fixed const& getY(void) const;

private:
	Fixed	const x;
	Fixed	const y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
