/* Dynamic_cast
You can only apply this operator to pointers and references to polymorphic class types,
which are class types that contain at least one virtual function. The reason is that only 
pointers to polymorphic class types contain the information that the dynamic_cast<>() operator
needs to check the validity of the conversion. */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base* generate(void){
	std::srand(std::time(NULL));
	int random = std::rand();

	if (random % 3 == 0)
		return new A();
	else if (random  % 3 == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p){
	A* testA = dynamic_cast<A*>(p);
	if (testA == NULL)
		std::cout << "Not type A\n";
	else
		std::cout << "Real type is A\n";

	B* testB = dynamic_cast<B*>(p);
	if (testB == NULL)
		std::cout << "Not type B\n";
	else
		std::cout << "Real type is B\n";

	C* testC = dynamic_cast<C*>(p);
	if (testC == NULL)
		std::cout << "Not type C\n";
	else
		std::cout << "Real type is C\n";
}

void identify(Base& p){
	try{
		(void)dynamic_cast<A&>(p);
		std::cout << "Real type is A\n";
	}
	catch (std::bad_cast &bc){
		std::cout << "Not type A\n";
	}

	try{
		(void)dynamic_cast<B&>(p);
		std::cout << "Real type is B\n";
	}
	catch (std::bad_cast &bc){
		std::cout << "Not type B \n";
	}
	
	try{
		(void)dynamic_cast<C&>(p);
		std::cout << "Real type is C\n";
	}
	catch (std::bad_cast &bc){
		std::cout << "Not type C\n";
	}
}

int	main(){

	Base* base = generate();

	identify(base); //pass as pointer
	identify(*base); //pass as reference
	delete base;

	system("leaks identify");
}
