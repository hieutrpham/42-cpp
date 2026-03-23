#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <cassert>
#include <iostream>

#define NUM_ANIMAL 2
static_assert(NUM_ANIMAL > 0, "ERR");

int main() {
	Animal* animals[NUM_ANIMAL];
	for (int i = 0; i < NUM_ANIMAL; ++i){
		if (i < NUM_ANIMAL/2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	std::cout<< "dog idea: "<< ((Dog*)(animals[0]))->getBrain()->getIdeas()[0] << std::endl;
	for (int i = 0; i < NUM_ANIMAL; ++i)
		delete animals[i];

	{
		Cat d;
		Cat d2(d);
		Cat d1 = d;
		std::cout << d.getType() << std::endl;
		std::cout << d2.getType() << std::endl;
		std::cout << d1.getType() << std::endl;
		d1.getBrain()->getIdeas()[0] = "good idea";
		std::cout<< d.getBrain()->getIdeas()[0] << std::endl;
		std::cout<< d1.getBrain()->getIdeas()[0] << std::endl;
	}
	{
		Dog d;
		Dog d2(d);
		Dog d1 = d;
		std::cout << d.getType() << std::endl;
		std::cout << d2.getType() << std::endl;
		std::cout << d1.getType() << std::endl;
		d1.getBrain()->getIdeas()[0] = "good idea";
		std::cout<< d.getBrain()->getIdeas()[0] << std::endl;
		std::cout<< d1.getBrain()->getIdeas()[0] << std::endl;
	}
	return 0;
}
