#include <iostream>
#include "Array.hpp"

int main()
{
	try
	{
		Array<int> emptyArray;
		std::cout << "emptyArray size: " << emptyArray.size() << std::endl;

		Array<int> intArray(5);
		std::cout << "intArray size: " << intArray.size() << std::endl;
		std::cout << "intArray[0] initial value: " << intArray[0] << std::endl;

		for (unsigned int i = 0; i < intArray.size(); i++)
			intArray[i] = i * 10;

		Array<int> copyArray(intArray);

		intArray[0] = 999;
		std::cout << "intArray[0]: " << intArray[0] << " (Modified)" << std::endl;
		std::cout << "copyArray[0]: " << copyArray[0] << " (Unaffected!)" << std::endl;

		Array<int> assignedArray;
		assignedArray = copyArray;

		copyArray[1] = 888;
		std::cout << "copyArray[1]: " << copyArray[1] << " (Modified)" << std::endl;
		std::cout << "assignedArray[1]: " << assignedArray[1] << " (Unaffected!)" << std::endl;

		Array<std::string> stringArray(3);
		stringArray[0] = "Hello";
		stringArray[1] = "Templates";
		stringArray[2] = "World";
		for (unsigned int i = 0; i < stringArray.size(); i++)
			std::cout << stringArray[i];
		std::cout << std::endl;

		std::cout << intArray[10] << std::endl; // should throw
	}
	catch (const std::exception& e) {
		std::cout << "ERROR: Caught exception: " << e.what() << std::endl;
	}
	return 0;
}
