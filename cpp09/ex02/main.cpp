#include "PmergeMe.hpp"

int main(int ac, char **av) {
	if (ac < 3)
	{
		std::cout << "Usage: " << av[0] << " [sequence of numbers to sort]\n";
		return 1;
	}
	
	std::vector<int> seq_vect;
	std::list<int>   seq_list;

	for (int i = 1; i < ac; ++i)
	{
		try {
			seq_vect.emplace_back(std::stoi(av[i]));
			seq_list.emplace_back(std::stoi(av[i]));
		} catch (...) {
			std::cerr << "ERR: invalid input\n";
			return 1;
		}
	}

	std::cout << "Before: ";
	for (int i = 1; i < ac; ++i)
	{
		if (i < ac - 1)
			std::cout << av[i] << " ";
		else if (i == ac - 1)
			std::cout << av[i];
	}
	std::cout << '\n';

    auto start = std::chrono::high_resolution_clock::now();
	PmergeMe p;
	p.ford_johnson(seq_vect);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    auto start_list = std::chrono::high_resolution_clock::now();
	p.ford_johnson(seq_list);
    auto end_list = std::chrono::high_resolution_clock::now();
    auto duration_list = std::chrono::duration_cast<std::chrono::microseconds>(end_list - start_list);

	std::cout << "After : ";
	for (auto i : seq_vect)
	{
		if (i != seq_vect.back())
			std::cout << i << " ";
		else
			std::cout << i;
	}
	std::cout << '\n';

	std::cout << "Time to process a range of " << seq_vect.size() << " elements with std::vector " << ": " << duration.count() << " us" << '\n';
	std::cout << "Time to process a range of " << seq_list.size() << " elements with std::list   " << ": " << duration_list.count() << " us" << '\n';
}
