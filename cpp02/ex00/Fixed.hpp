#pragma once

class Fixed {
private:
	int num;
	static const int bit = 8;
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &copy);
	Fixed& operator=(const Fixed& other);
	int getRawBits(void) const;
	void setRawBits(int const raw);
};
