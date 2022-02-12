#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <list>
#include <deque>

int main(){

	std::cout << "\n -- VECTOR TEST --  " << std::endl;
	std::vector<int> vectorT;
	vectorT.push_back(1);
	vectorT.push_back(6);
	vectorT.push_back(8);
	vectorT.push_back(2);

	try{
		std::vector<int>::iterator found = easyfind(vectorT, 8);
		std::cout << "int found: " << *found << std::endl;
	}
	catch(NotFoundException& e){
		std::cout << e.what() << std::endl;
	}
	try{
		std::vector<int>::iterator found = easyfind(vectorT, 3);
		std::cout << "int found: " << *found << std::endl;
	}
	catch(NotFoundException& e){
		std::cout << e.what() << std::endl;
	}


	std::cout << "\n -- DEQUE TEST --  " << std::endl;
	std::deque<int> dequeT;
	dequeT.push_back(90);
	dequeT.push_back(3);
	dequeT.push_back(121);
	dequeT.push_back(-3);

	try{
		std::deque<int>::iterator found = easyfind(dequeT, 121);
		std::cout << "int found: " << *found << std::endl;
	}
	catch(NotFoundException& e){
		std::cout << e.what() << std::endl;
	}
	try{
		std::deque<int>::iterator found = easyfind(dequeT, 200);
		std::cout << "int found: " << *found << std::endl;
	}
	catch(NotFoundException& e){
		std::cout << e.what() << std::endl;
	}



	std::cout << "\n -- LIST TEST --  " << std::endl;
	std::list<int> listT;
	listT.push_back(0);
	listT.push_back(20);
	listT.push_back(12);
	listT.push_back(10000);

	try{
		std::list<int>::iterator found = easyfind(listT, 0);
		std::cout << "int found: " << *found << std::endl;
	}
	catch(NotFoundException& e){
		std::cout << e.what() << std::endl;
	}
	try{
		std::list<int>::iterator found = easyfind(listT, 333);
		std::cout << "int found: " << *found << std::endl;
	}
	catch(NotFoundException& e){
		std::cout << e.what() << std::endl;
	}
	

	std::cout << "\n -- SET TEST --  " << std::endl;
	std::set<int> setT;
	setT.insert(33);
	setT.insert(34);
	setT.insert(35);
	setT.insert(36);

	try{
		std::set<int>::iterator found = easyfind(setT, 35);
		std::cout << "int found: " << *found << std::endl;
	}
	catch(NotFoundException& e){
		std::cout << e.what() << std::endl;
	}
	try{
		std::set<int>::iterator found = easyfind(setT, -10);
		std::cout << "int found: " << *found << std::endl;
	}
	catch(NotFoundException& e){
		std::cout << e.what() << std::endl;
	}
}
