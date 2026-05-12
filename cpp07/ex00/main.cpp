#include <iostream>
#include "whatever.hpp"

int main()
{
	int a = 2;
	int b = 3;

	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	std::string c = "string1";
	std::string d = "string2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

	int e = 5, f = 5;
	std::cout << "min(5, 5) = " << ::min(e, f) << std::endl;
	std::cout << "max(5, 5) = " << ::max(e, f) << std::endl;

	int g = 42;
	std::cout << "before swap: g = " << g << std::endl;
	::swap(g, g);
	std::cout << "after swap(g, g): g = " << g << std::endl;

	int h = -5;
	int i = -3;
	std::cout << "min(-5, -3) = " << ::min(h, i) << std::endl;
	std::cout << "max(-5, -3) = " << ::max(h, i) << std::endl;

	float j = 1.1f;
	float k = 1.2f;
	std::cout << "before swap: j = " << j << ", k = " << k << std::endl;
	::swap(j, k);
	std::cout << "after swap: j = " << j << ", k = " << k << std::endl;
	std::cout << "min(j, k) = " << ::min(j, k) << std::endl;
	std::cout << "max(j, k) = " << ::max(j, k) << std::endl;

	return 0;
}
