#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"

int main()
{
	std::srand(std::time(NULL));
	try
	{
		Base* random_obj = generate();

		std::cout << "Identifying via pointer: ";
		identify(random_obj);

		std::cout << "Identifying via reference: ";
		identify(*random_obj);
		delete random_obj;
	}
	catch (const std::exception& e)
	{
		std::cerr << "An unexpected error occurred: " << e.what() << "\n";
		return 1;
	}
	return 0;
}
