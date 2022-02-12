#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>
# include <string.h>
# include <iomanip> 

template<typename T>
void	iter(T* array, int len, void(func)(T)){
	for(int i = 0; i < len; i++){
		func(array[i]);
	}
}

template<typename T>
void	printValue(T value){
	std::cout << value << std::endl;
}

#endif
