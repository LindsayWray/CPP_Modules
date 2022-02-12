#include "Zombie.hpp"

int main(){
	Zombie *heapy = newZombie("Heapy");
	heapy->announce();
	randomChump("Stacky"); //compiler destroys when lifetime is over
	delete heapy;  //heap needs delete to be destroyed
}
