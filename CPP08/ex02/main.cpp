#include "MutantStack.hpp"
#include <list>

void	testMutantStack(){
	std::cout << "\n  --MUTANTSTACK TESTS --  " << std::endl;
	MutantStack<int> mstack;
	
	std::cout << "mutantstack is empty	" << mstack.empty() << std::endl;
	

	mstack.push(5);
	mstack.push(17);

	std::cout << "top element	" << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "top element	" << mstack.top() << std::endl;

	std::cout << "stack size	" << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	std::cout << "  --ITERATOR TEST --  " << std::endl;
	int index = 0;
	while (it != ite){
		std::cout << "index " << index << ":  " <<  *it << std::endl;
		++it;
		index++;
	}

	MutantStack<int>::reverseIterator rit = mstack.rbegin();
	MutantStack<int>::reverseIterator rite = mstack.rend();

	++rit;
	--rit;
	std::cout << "  --REVERSE ITERATOR TEST --  " << std::endl;
	int i = 0;
	while (rit != rite){
		std::cout << "index " << i << ":  " <<  *rit << std::endl;
		++rit;
		i++;
	}


	std::stack<int> s(mstack);

	MutantStack<int> m = mstack;
	std::cout << "  --TEST ASSIGNMENT OPERATOR--  " << std::endl;
	std::cout << "top element	" << m.top() << std::endl;
	m.pop();
	std::cout << "top element	" << m.top() << std::endl;
	m.pop();
	std::cout << "top element	" << m.top() << std::endl;

	std::cout << "  --ORIGINAL UNAFFECTED--  " << std::endl;
	it = mstack.begin();
	ite = mstack.end();
	index = 0;
	while (it != ite){
		std::cout << "index " << index << ":  " << *it << std::endl;
		++it;
		index++;
	}
}




void	testList(){
	std::cout << "\n  --LIST TESTS --  " << std::endl;
	std::list<int> list;
	
	std::cout << "list is empty	" << list.empty() << std::endl;

	list.push_back(5);
	list.push_back(17);

	std::cout << "last element	" << list.back() << std::endl;
	list.pop_back();
	std::cout << "last element	" << list.back() << std::endl;

	std::cout << "list size	" << list.size() << std::endl;

	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	//[...]
	list.push_back(0);

	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator ite = list.end();

	++it;
	--it;
	std::cout << "  --ITERATOR TEST --  " << std::endl;
	int index = 0;
	while (it != ite){
		std::cout << "index " << index << ":  " << *it << std::endl;
		++it;
		index++;
	}

	std::list<int>::reverse_iterator rit = list.rbegin();
	std::list<int>::reverse_iterator rite = list.rend();

	++rit;
	--rit;
	std::cout << "  --REVERSE ITERATOR TEST --  " << std::endl;
	int i = 0;
	while (rit != rite){
		std::cout << "index " << i << ":  " <<  *rit << std::endl;
		++rit;
		i++;
	}

	//std::stack<int> s(list);

	std::list<int> m = list;
	std::cout << "  --TEST ASSIGNMENT OPERATOR--  " << std::endl;
	std::cout << m.back() << std::endl;
	m.pop_back();
	std::cout << m.back() << std::endl;
	m.pop_back();
	std::cout << m.back() << std::endl;

	std::cout << "  --ORIGINAL UNAFFECTED--  " << std::endl;
	it = list.begin();
	ite = list.end();
	index = 0;
	while (it != ite){
		std::cout << "index " << index << ":  " << *it << std::endl;
		++it;
		index++;
	}
}

int main(){
	testMutantStack();
	testList();
}
