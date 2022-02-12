// BSP stands for Binary space partitioning
#include "Point.hpp"

Fixed sign (Point p1, Point p2, Point p3){
	return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

bool bsp(Point const a, Point const b, Point const c, Point const point){
	Fixed AB, BC, CA;

	AB = sign(point, a, b);
	BC = sign(point, b, c);
	CA = sign(point, c, a);

	if ( ((AB < 0) && (BC < 0) && (CA < 0)) || ((AB > 0) && (BC > 0) && (CA > 0)) )
		return true;
	return false;
}
