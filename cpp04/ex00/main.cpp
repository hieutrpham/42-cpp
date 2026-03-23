#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <memory>

int main() {
	std::unique_ptr<Animal> a = std::make_unique<Animal>();
	std::unique_ptr<Animal> d = std::make_unique<Dog>();
	std::unique_ptr<Animal> c = std::make_unique<Cat>();
	
	std::cout << a->getType() << std::endl;
	std::cout << d->getType() << std::endl;
	std::cout << c->getType() << std::endl;
	a->makeSound();
	d->makeSound();
	c->makeSound();
	std::unique_ptr<WrongAnimal> wa = std::make_unique<WrongAnimal>();
	std::unique_ptr<WrongAnimal> wc = std::make_unique<WrongCat>();
	wa->makeSound();
	wc->makeSound();
	return 0;
}
