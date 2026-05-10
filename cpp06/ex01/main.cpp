#include <format>
#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data myData;

	std::cout << "Original Data address: " << &myData << "\n";
	std::cout << "Original Data values: id = " << myData.id << ", name = "
				<< myData.name << "\n\n";

	auto raw_integer = Serializer::serialize(&myData);
	std::cout << std::format("Serialized integer: {:#x}\n\n", raw_integer);

	auto deserialized_ptr = Serializer::deserialize(raw_integer);
	std::cout << "Deserialized address: " << deserialized_ptr << "\n";

	if (deserialized_ptr == &myData)
	{
		std::cout << "SUCCESS! The addresses match.\n";
		std::cout << "Recovered values: id = " << deserialized_ptr->id
				<< ", name = " << deserialized_ptr->name << "\n";
	}
	else
		std::cout << "FAILURE! The addresses do not match.\n";
	return 0;
}
