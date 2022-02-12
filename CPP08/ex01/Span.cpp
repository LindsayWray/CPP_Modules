#include "Span.hpp"

Span::Span() : _N(0){}

Span::Span(unsigned int N) : _N(N){
}

Span::Span(Span const& original){
	*this = original;
}

Span::~Span(){}

Span& Span::operator=(Span const& original){
	_N = original._N;
	_storage = std::vector<int>(original._storage);
	return *this;
}

void	Span::addNumber(int num){
	if(_storage.size() >= _N)
		throw(Span::StorageFullException());
	_storage.push_back(num);
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end){
	
	_storage.insert(_storage.end(), begin, end);
	if(_storage.size() > _N)
		throw(Span::StorageFullException());
		
	// FOR TESTING PURPOSES
	// for(std::vector<int>::iterator it = _storage.begin(); it != _storage.end(); it++){
	// 	std::cout << *it << ", ";
	// }
	// std::cout << std::endl;
}

unsigned int Span::shortestSpan() const{
	if(_storage.size() < 2)
		throw(Span::NoSpanException());

	std::vector<int> copy(_storage);
	std::sort(copy.begin(), copy.end());
	std::adjacent_difference(copy.begin(), copy.end(), copy.begin());
	return *(std::min_element(copy.begin() + 1, copy.end()));
}

unsigned int Span::longestSpan() const{
	if(_storage.size() < 2)
		throw(Span::NoSpanException());
	return *(std::max_element(_storage.begin(), _storage.end())) - *(std::min_element(_storage.begin(), _storage.end()));
}
