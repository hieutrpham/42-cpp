#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <memory>

int main() {
	// std::unique_ptr<Animal> a = std::make_unique<Animal>();
	const Animal *a = new Animal();
	
	const Animal *d = new Dog();
	const Animal *c = new Cat();
	std::cout << a->getType() << std::endl;
	std::cout << d->getType() << std::endl;
	std::cout << c->getType() << std::endl;
	a->makeSound();
	d->makeSound();
	c->makeSound();
	delete a;
	delete d;
	delete c;
	WrongAnimal *wa = new WrongAnimal();
	WrongAnimal *wc = new WrongCat();
	wa->makeSound();
	wc->makeSound();
	return 0;
}
