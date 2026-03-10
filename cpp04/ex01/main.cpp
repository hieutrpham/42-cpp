#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
	Animal* animals[4];
	animals[0] = new Dog();
	animals[1] = new Dog();
	animals[2] = new Cat();
	animals[3] = new Cat();
	for (int i = 0; i < 4; ++i)
		delete animals[i];

	// Animal *c1 = new Cat();
	// Animal *c2 = new Dog();
	// c1 = c2;
	// delete c1;
	// delete c2;
	return 0;
}
