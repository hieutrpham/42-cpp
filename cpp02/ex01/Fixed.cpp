#include "Fixed.hpp"
#include <cmath>
#include <iostream>
#include <ostream>

Fixed::Fixed() : num(0) {
	std::cout << "default constructor called\n";
}

Fixed::Fixed(int param) : num(param << bit) {
	std::cout << "int constructor called\n";
}

Fixed::Fixed(float param) : num(std::roundf(param * (1 << bit))) {
	std::cout << "float constructor called\n";
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

float Fixed::toFloat(void) const {
	return static_cast<float>(this->num) / static_cast<float>(1 << this->bit);
}

int Fixed::toInt(void) const {
	return this->num >> this->bit;
}

std::ostream& operator<<(std::ostream& os, const Fixed& f) {
	os << f.toFloat();
	return os;
}
