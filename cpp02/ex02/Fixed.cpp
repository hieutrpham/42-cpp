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

Fixed::Fixed(const Fixed &copy) : num(copy.num) {
	std::cout << "copy constructor called\n";
}

Fixed& Fixed::operator=(const Fixed& other) {
	// std::cout << "copy assignment operator called\n";
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
	return (float)this->num / (float)(1 << this->bit);
}

int Fixed::toInt(void) const {
	return this->num >> this->bit;
}

bool Fixed::operator!=(const Fixed& other) {
	return this->num != other.num;
}
bool Fixed::operator==(const Fixed& other) {
	return this->num == other.num;
}

bool Fixed::operator>=(const Fixed& other) {
	return this->num >= other.num;
}

bool Fixed::operator<=(const Fixed& other) {
	return this->num <= other.num;
}
bool Fixed::operator>(const Fixed& other) {
	return this->num > other.num;
}

bool Fixed::operator<(const Fixed& other) {
	return this->num < other.num;
}

Fixed Fixed::operator+(const Fixed& other) {
	Fixed ret;
	ret.setRawBits(this->num + other.num);
	return ret;
}

Fixed Fixed::operator-(const Fixed& other) {
	Fixed ret;
	ret.setRawBits(this->num - other.num);
	return ret;
}

Fixed Fixed::operator*(const Fixed& other) {
	Fixed ret;
	auto temp = (this->num * other.num) >> this->bit;
	ret.setRawBits(temp);
	return ret;
}

Fixed Fixed::operator/(const Fixed& other) {
	Fixed ret;
	auto temp = (this->num << this->bit) / other.num;
	ret.setRawBits(temp);
	return ret;
}

Fixed& Fixed::operator--() {
	this->num--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	operator--();
	return temp;
}
Fixed& Fixed::operator++() {
	this->num++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	operator++();
	return temp;
}

const Fixed& Fixed::min(Fixed& one, Fixed& two) {
	if (one <= two)
		return one;
	else
		return two;
}

const Fixed& Fixed::min(const Fixed& one, const Fixed& two) {
	if (one.num <= two.num)
		return one;
	else
		return two;
}

const Fixed& Fixed::max(Fixed& one, Fixed& two) {
	if (one <= two)
		return two;
	else
		return one;
}

const Fixed& Fixed::max(const Fixed& one, const Fixed& two) {
	if (one.num <= two.num)
		return two;
	else
		return one;
}

std::ostream& operator<<(std::ostream& os, const Fixed& f) {
	os << f.toFloat();
	return os;
}
