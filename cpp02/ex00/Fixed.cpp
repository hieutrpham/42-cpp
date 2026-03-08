#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : num(0) {
	std::cout << "default constructor called\n";
}

Fixed::~Fixed() {
	std::cout << "destructor called\n";
}

Fixed::Fixed(const Fixed &copy) : num(copy.num){
	std::cout << "copy constructor called\n";
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "copy assignment operator called\n";
	if (this != &other)
		this->num = other.num;
	return *this;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawbits member function called\n";
	return this->num;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawbits member function called\n";
	this->num = raw;
}
