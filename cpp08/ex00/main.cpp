#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <string>
#include "easyfind.hpp"

int main()
{
	std::cout << "TEST 1: std::vector\n";
	std::vector<int> vec = {10, 20, 30, 40, 50};
	
	try {
		auto it = easyfind(vec, 30);
		std::cout << "Found: " << *it << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "Searching for 99 (should throw exception)" << std::endl;
	try {
		auto it = easyfind(vec, 99);
		std::cout << "Found: " << *it << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nTEST 2: std::list\n";
	std::list<int> lst = {100, 200, 300};

	try {
		auto it = easyfind(lst, 200);
		std::cout << "Found: " << *it << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nTEST 3: std::deque\n";
	std::deque<int> dq = {7, 8, 9};

	try {
		auto it = easyfind(dq, 9);
		std::cout << "Found: " << *it << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	const std::vector<int> constVec = {3, 14, 15, 92, 65, 35};
	std::vector<int> constTests = {14, 92, 0, 7, 65, 100};

	for (int val : constTests) {
		try {
			typename std::vector<int>::const_iterator it = easyfind(constVec, val);
			std::cout << "Found: " << *it << "\n";
		}
		catch(const std::exception& e) {
			std::cout << "Error: " << e.what() << '\n';
		}
	}
}
