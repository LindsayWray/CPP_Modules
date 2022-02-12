#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
# define MAX_VAL 750

template<typename T>
class Array{
private:
	T* _array;
	unsigned int _size;
public:
	Array() : _array(new T[0]), _size(0) {}; //empty array
	Array(unsigned int n) : _array(new T[n]), _size(n) {}; //makes an array of T's
	Array(Array const& original) : _array(NULL) {
		*this = original;
	};
	~Array(){
		delete[] _array;
	};

	Array&	operator=(Array const& original){
		delete[] _array;
		_size = original._size;
		_array = new T[_size];
		for(unsigned int i = 0; i < _size; i++){
			_array[i] = original._array[i];
		}
		return *this;
	};

	T& operator[](unsigned int index) const{  //Array subscript operator
		if (index < 0 || index >= _size)
			throw(Array::IndexOutofBoundsException());
		return _array[index];
	};
	
	unsigned int	size(void) const{
		return _size;
	};

	class IndexOutofBoundsException : public std::exception{
	public:
		const char* what() const throw(){
			return "Requested index is out of bounds";
		}
	};

};
#endif
