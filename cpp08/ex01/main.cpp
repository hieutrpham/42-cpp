#include "Span.hpp"
#include <iostream>
#include <vector>
#include <numeric>

int main()
{
	try {
		std::cout << "TEST 1: Basic subject example\n";
		Span sp = Span(5);

		int nums[] = {6, 3, 17, 9, 11};
		for (size_t i = 0; i < sizeof(nums)/sizeof(*nums); ++i)
			sp.addNumber(nums[i]);

		std::cout << "--- Results ---\n";
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;

		std::cout << "Longest span: " << sp.longestSpan() << std::endl;

		std::cout << "\nTEST 2: Range-based addNumbers with 10000 integers\n";
		std::vector<int> bigVec(10000);
		std::iota(bigVec.begin(), bigVec.end(), 20);

		Span bigSpan(10000);
		try {
			bigSpan.addNumbers(bigVec);
		} catch (const std::exception& e) {
			std::cout << "EXCEPTION: " << e.what() << "\n";
			return 1;
		}

		std::cout << "--- Results ---\n";
		std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;

		std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;
		std::cout << "\n";

		std::cout << "TEST 3: Exception - adding to a full span";
		std::cout << "\n --- Results ---\n";
		try {
			sp.addNumber(42);
		} catch(const std::exception& e) {
			std::cout << "Caught exception: " << e.what() << std::endl;
		}

		std::cout << "\nTEST 4: Exception - not enough numbers for a span\n";
		std::cout << "--- Results ---\n";
		try {
			Span tiny(10);
			tiny.addNumber(42);
			std::cout << tiny.shortestSpan() << std::endl;
		} catch(const std::exception& e) {
			std::cout << "Caught exception: " << e.what() << std::endl;
		}
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
