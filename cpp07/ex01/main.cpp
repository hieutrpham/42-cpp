#include <iostream>
#include "iter.hpp"
#include <string>

template <typename T>
void print(const T& element)
{
	std::cout << element << std::endl;
}

template<typename T>
void double_(T& element)
{
	element *= 2;
}

int main()
{
	int ints[] = {1, 2, 3, 4, 5};
	std::cout <<  "== Test 1: int array ==" << std::endl;
	iter(ints, 5, print<int>);

	std::string words[] = {"hello", "world", "templates"};
	std::cout << "\n== Test 2: string array with print ==" << std::endl;
	iter(words, 3, print<std::string>);

	std::cout << "\n== Test 3: doubled ints ==" << std::endl;
	iter(ints, 5, double_<int>);
	iter(ints, 5, print<int>);

	std::cout << "\n== Test 4: const array ==" << std::endl;
	const int consts[] = {10, 20, 30};
	iter(consts, 3, print<int>);
}
