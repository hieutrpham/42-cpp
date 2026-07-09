#include <algorithm>
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

	std::cout << "Recursion level: " << level << "\n";
	printf("main chain: ");
	for (auto i : main_chain)
		std::cout << i << ",";
	std::cout << "\n";

	std::cout << "pend_chain: ";
	for (auto i : pend_chain)
		std::cout << i << ",";
	std::cout << "\n";

	// for (size_t i = 0; i < pairs.size(); ++i)
	// 	std::cout << pairs[i].first << " " << pairs[i].second << "\n";

	foo(main_chain, level + 1);

	// TODO: insert pend_chain into main_chain using Jacob sequence

}

#if 1
int main(int ac, char **av) {
	if (ac < 3)
	{
		std::cout << "Usage: " << av[0] << " [sequence of numbers to sort]\n";
		return 1;
	}

	// std::vector<int> test_sequence = {11,2,17,0,16,8,6,15,10,3,21,1,18,9,14,19,12,5,4,20,13,7};
	std::vector<int> test_sequence = {30,49,60,1,31,29,42,46,13,8,5};

	std::cout << "Original sequence: ";
	for (auto i: test_sequence)
		std::cout << i << ' ';
	std::cout << "\n\n";
	foo(test_sequence, 1);
}

#else
int main ()
{
	std::vector<int> test_sequence = {0, 1, 2, 4, 5};
	auto it = std::lower_bound(test_sequence.begin(), test_sequence.end(), 3);
	test_sequence.insert(it, 3);
	for (auto i : test_sequence)
		std::cout << i << " ";
}
#endif
