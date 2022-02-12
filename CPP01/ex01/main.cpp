#include "Zombie.hpp"

int main(){
	int N = 4;

	Zombie *horde = zombieHorde(N, "Heapy");
	for(int i = 0; i < N; i++){
		horde[i].announce();
	}
	delete[] horde;
}
