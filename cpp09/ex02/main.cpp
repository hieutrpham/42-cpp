#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdint>

void foo(std::vector<int> &v, int level)
{
	if (v.size() <= 1)
		return;

	// break sequence into sorted pairs
	std::vector<std::pair<int, int>> pairs;
	for (size_t i = 0; i + 1 < v.size(); i += 2)
	{
		int a = v[i];
		int b = v[i + 1];
		if (a >= b)
			pairs.push_back(std::make_pair(b, a));
		else
			pairs.push_back(std::make_pair(a, b));
	}
	
	// initialize main and pend chain
	std::vector<int> main_chain, pend_chain;

	size_t pair_i = 0;
	for (; pair_i < pairs.size(); ++pair_i)
	{
		main_chain.push_back(pairs[pair_i].second);
		pend_chain.push_back(pairs[pair_i].first);
	}

	// if there are left over numbers, append to pend chain
	if (v.size() % 2)
	{
		pend_chain.push_back(v[pair_i * 2]);
	}

	std::cout << "\nRecursion level: " << level << "\n";
	printf("main chain before recursion: ");
	for (auto i : main_chain)
		std::cout << i << ",";
	printf("\n");

	std::cout << "pend_chain: ";
	for (auto i : pend_chain)
		std::cout << i << ",";
	printf("\n\n");

	foo(main_chain, level + 1);

	printf("main chain after recursion: ");
	for (auto i : main_chain)
		std::cout << i << " ";
	printf("\n");

	printf("pend chain after recursion: ");
	for (auto i : pend_chain)
		std::cout << i << " ";
	printf("\n\n");

	// TODO: insert pend_chain into main_chain
	for (auto value : pend_chain)
	{
		auto it = std::lower_bound(main_chain.begin(), main_chain.end(), value);
		main_chain.insert(it, value);
	}

	printf("main chain after inserted: ");
	for (auto i : main_chain)
		std::cout << i << " ";

	// realigned main_chain from previous recursion level to the sorted one
	v = main_chain;
	printf("\n");
}

#if 1
int main(int ac, char **av) {
	(void)ac;
	(void)av;
	// if (ac < 3)
	// {
	// 	std::cout << "Usage: " << av[0] << " [sequence of numbers to sort]\n";
	// 	return 1;
	// }

	// std::vector<int> test_sequence = {11,2,17,0,16,8,6,15,10,3,21,1,18,9,14,19,12,5,4,20,13,7};
	std::vector<int> test_sequence = {30,49,60,1,31,29,42,46,13,8,5};

	printf("\nPmergeme Version 1.23423b\n\n");
	std::cout << "Original sequence: ";
	for (auto i: test_sequence)
		std::cout << i << ' ';
	std::cout << "\n";
	foo(test_sequence, 1);
}

#else
int main ()
{
	std::vector<int> test_sequence = {46, 60};
	auto value = 49;
	auto it = std::lower_bound(test_sequence.begin(), test_sequence.end(), value);
	test_sequence.insert(it, value);
	for (auto i : test_sequence)
		std::cout << i << " ";
}
#endif
