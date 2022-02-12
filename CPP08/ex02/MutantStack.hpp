#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <iostream>
# include <string>
# include <vector>
# include <stack>

template<typename T>
class MutantStack : public std::stack<T>{
public:
	MutantStack(){};
	~MutantStack(){};
	MutantStack(MutantStack const& original) {
		*this = original;
	};

	MutantStack& operator=(MutantStack const& original){
		std::stack<T>::operator=(original);
		return *this;
	};

	typedef typename std::deque<T>::iterator iterator;
	typedef typename std::deque<T>::reverse_iterator reverseIterator; 
	
	iterator begin(){
		return this->c.begin(); //c is the underlying container, deque
	};
	iterator end(){
		return this->c.end();
	};
	reverseIterator rbegin(){
		return this->c.rbegin();
	};
	reverseIterator rend(){
		return this->c.rend();
	};
};


#endif
