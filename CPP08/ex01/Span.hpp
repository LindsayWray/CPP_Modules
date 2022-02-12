#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <string>
# include <vector>
# include <numeric>

class Span{
private:
	unsigned int		_N;
	std::vector<int>	_storage;
	Span();
public:
	Span(unsigned int N);
	Span(Span const& original);
	~Span();

	Span& operator=(Span const& original);

	void			addNumber(int num);
	void			addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	unsigned int	shortestSpan() const;
	unsigned int	longestSpan() const;

	class StorageFullException : public std::exception{
	public:
		const char* what() const throw(){
			return "Exception: maximum amount of elements stored in the object";
		}
	};

	class NoSpanException : public std::exception{
	public:
		const char* what() const throw(){
			return "Exception: too few elements to determine span";
		}
	};
};

#endif
