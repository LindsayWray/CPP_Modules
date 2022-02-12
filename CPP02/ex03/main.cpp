#include "Point.hpp"

int main(void){
	bool in_triangle = bsp(Point(0,0), Point(0,5), Point(5,0), Point(2,2));
	std::cout << in_triangle << std::endl;

	bool not_in_triangle = bsp(Point(0,0), Point(0,5), Point(5,0), Point(7,2));
	std::cout << not_in_triangle << std::endl;

	bool on_triangle_line = bsp(Point(0,0), Point(0,5), Point(5,0), Point(0,3));
	std::cout << on_triangle_line << std::endl;
}
