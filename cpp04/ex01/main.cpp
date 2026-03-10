#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <cstdio>
#include <iostream>

#define NUM_ANIMAL 40

int main() {
	Animal* animals[NUM_ANIMAL];
	for (int i = 0; i < NUM_ANIMAL; ++i){
		if (i < NUM_ANIMAL/2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < NUM_ANIMAL; ++i)
		delete animals[i];

	Animal c1;
	Cat c2(new Cat());
	printf("%p\n", &c1);
	printf("%p\n", &c2);
	// delete c1;
	// delete c2;
	return 0;
}
