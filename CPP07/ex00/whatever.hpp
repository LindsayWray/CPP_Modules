#ifndef WHATEVER_HPP
# define WHATEVER_HPP
# include <iostream>

template<typename T>
void	swap(T& value1, T& value2){
	T temp = value2;
	value2 = value1;
	value1 = temp;
}

template<typename T>
T	min(T const& value1, T const& value2){
	if (value1 < value2)
		return value1;
	return value2;
}

template<typename T>
T	max(T const& value1, T const& value2){
	if (value1 > value2)
		return value1;
	return value2;
}

#endif
