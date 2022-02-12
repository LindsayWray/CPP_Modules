#include "Span.hpp"

int main()
{
	Span sp = Span(5);

	std::cout << "\n -- NO ELEMENTS TEST --  " << std::endl;
	try{
		//std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(Span::NoSpanException& e){
		std::cout << e.what() << std::endl;
	}

	sp.addNumber(6);
	std::cout << "\n -- ONE ELEMENT TEST --  " << std::endl;
	try{
		//std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(Span::NoSpanException& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n -- FILLED VECTOR TESTS --  " << std::endl;
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "longest span: " << sp.longestSpan() << std::endl;

	std::cout << "\n -- MAX CAPACITY TEST --  " << std::endl;
	try{
		sp.addNumber(11);
	}
	catch(Span::StorageFullException& e){
		std::cout << e.what() << std::endl;
	}

	std::vector<int> largeVector;
	srand(time(NULL));
	for(int i = 0; i < 100000; i++){
		largeVector.push_back(std::rand() % 100);
	// //	std::cout << largeVector[i] << std::endl;
	}

	Span largeSpan = Span(100000);
	std::cout << "\n -- 100.000 NUMBERS TEST --  " << std::endl;
	try{
		largeSpan.addNumber(largeVector.begin(), largeVector.end());
	}
	catch(Span::StorageFullException& e){
		std::cout << e.what() << std::endl;
	}
	try{
	std::cout << "shortest span: " << largeSpan.shortestSpan() << std::endl;
	std::cout << "longest span: " << largeSpan.longestSpan() << std::endl;
	}
	catch(Span::NoSpanException& e){
		std::cout << e.what() << std::endl;
	}



	std::cout << "\n -- TEST ADDING MULTIPLE VECTORS --  " << std::endl;
	std::vector<int> randVector1;
	srand(time(NULL));
	for(int i = 0; i < 10; i++){
		randVector1.push_back(std::rand() % 1000);
		std::cout << randVector1[i] << ", ";
	}
	std::cout << std::endl;
	std::vector<int> randVector2;
	for(int i = 0; i < 10; i++){
		randVector2.push_back(std::rand() % 1000);
		std::cout << randVector2[i] << ", ";
	}
	std::cout << std::endl;

	Span randSpan = Span(20);
	try{
		randSpan.addNumber(randVector1.begin(), randVector1.end());
		randSpan.addNumber(randVector2.begin(), randVector2.end());
	}
	catch(Span::StorageFullException& e){
		std::cout << e.what() << std::endl;
	}
	try{
	std::cout << "shortest span: " << randSpan.shortestSpan() << std::endl;
	std::cout << "longest span: " << randSpan.longestSpan() << std::endl;
	}
	catch(Span::NoSpanException& e){
		std::cout << e.what() << std::endl;
	}
}
