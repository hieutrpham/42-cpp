#pragma once

#include <ostream>

class Fixed {
private:
	int num;
	static const int bit = 8;
public:
	Fixed();
	Fixed(const int param);
	Fixed(const float param);
	~Fixed();
	Fixed(const Fixed &copy);
	Fixed& operator=(const Fixed& other);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;
	Fixed operator+(const Fixed& other);
	Fixed operator-(const Fixed& other);
	Fixed operator*(const Fixed& other);
	Fixed operator/(const Fixed& other);
	Fixed& operator--();
	Fixed operator--(int);
	Fixed& operator++();
	Fixed operator++(int);
	static Fixed& min(Fixed& one, Fixed& two);
	static const Fixed& min(const Fixed& one, const Fixed& two);
	static Fixed& max(Fixed& one, Fixed& two);
	static const Fixed& max(const Fixed& one, const Fixed& two);
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);
