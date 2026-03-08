#pragma once

#include <ostream>

class Fixed {
public:
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
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);
