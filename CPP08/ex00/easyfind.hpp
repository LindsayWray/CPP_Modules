#ifndef EASYFIND_HPP
# define EASYFIND_HPP
#include <algorithm> 

class NotFoundException : public std::exception{
public:
	const char* what() const throw(){
		return "Exception: integer not found";
	}
};

template<typename T>
typename T::iterator	easyfind(T &type, int num){

	typename T::iterator it;

	it = std::find(type.begin(), type.end(), num);
	if (it == type.end())
		throw(NotFoundException());
	return it;
}

#endif
