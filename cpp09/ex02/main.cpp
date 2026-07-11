#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdint>

static std::vector<int> jacobsthal = {3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525};

int get_pair_index(int first, std::vector<std::pair<int, int>> pairs, std::vector<int> main_chain)
{
	int index = -1;
	int second = -1;

	for (size_t i = 0; i < pairs.size(); ++i)
	{
		if (first == pairs[i].first)
			second = pairs[i].second;
	}

	for (size_t j = 0; j < main_chain.size(); ++j)
	{
		if (second == main_chain[j])
			index = j;
	}

	return index;
}

std::vector<int> jacob_gen(size_t pend_size)
{
	std::vector<int> jacob_index = {};

	int x;

	for (size_t i = 0; i < jacobsthal.size(); ++i)
	{
		x = jacobsthal[i];
		while (x > 1 && jacob_index.size() < pend_size)
		{
			if (std::find(jacob_index.begin(), jacob_index.end(), x) == jacob_index.end())
				jacob_index.push_back(x);
			x--;
		}
	}

	return jacob_index;
}

// source: https://medium.com/@mohammad.ali.ibrahim.525/ford-johnson-algorithm-merge-insertion-4b024f0c3d42
void ford_johnson(std::vector<int> &v, int level)
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
	printf("main chain before recursion: ");
	for (auto i : main_chain)
		std::cout << i << ",";
	printf("\n");

	printf("pend_chain                 : ");
	for (auto i : pend_chain)
		std::cout << i << ",";
	printf("\n\n");

	// NOTE: recurse on main_chain
	ford_johnson(main_chain, level + 1);

	printf("\nUnwinding level: %d\n", level);
	printf("main chain after recursion: ");
	for (auto i : main_chain)
		std::cout << i << " ";
	printf("\n");

	// aligning new pend to the new main
	std::vector<int> new_pend;
	for (size_t i = 0; i < main_chain.size(); ++i)
	{
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (main_chain[i] == pairs[j].second)
				new_pend.push_back(pairs[j].first);
		}
	}

	std::vector<int> jacob = jacob_gen(new_pend.size());
	std::cout << "jacob: ";
	for (auto i :jacob)
		std::cout << i << ' ';
	std::cout << "\n";

	if (pend_chain.size() > new_pend.size())
		new_pend.push_back(pend_chain.back());

	printf("new pend size: %zu\n", new_pend.size());
	printf("new pend                  : ");
	for (size_t i = 0; i < new_pend.size(); ++i)
	{
		printf("%d, ", new_pend[i]);
	}
	printf("\n");

	// insert the first number from pend
	main_chain.insert(main_chain.begin(), new_pend[0]);

	// insert based on the jacob sequence
	for (size_t i = 0; i < jacob.size(); ++i)
	{
		size_t index = jacob[i] - 1;
		if (index < new_pend.size())
		{
			auto main_index = get_pair_index(new_pend[index], pairs, main_chain);
			if (main_index > 0)
			{
				auto it = std::lower_bound(main_chain.begin(), main_chain.begin() + main_index, new_pend[index]);
				main_chain.insert(it, new_pend[index]);
			}
		}
	}

	// insert any leftover from pend
	for (auto it = new_pend.rbegin(); it != new_pend.rend(); ++it)
	{
		if (std::find(main_chain.begin(), main_chain.end(), *it) == main_chain.end())
		{
			auto mit = std::lower_bound(main_chain.begin(), main_chain.end(), *it);
			main_chain.insert(mit, *it);
		}
	}

	printf("main chain after inserted : ");
	for (auto i : main_chain)
		std::cout << i << " ";

	// realigned main_chain from previous recursion level to the sorted one
	v = main_chain;
	printf("\n");
}

#if 1
int main(int ac, char **av) {
	if (ac < 3)
	{
		std::cout << "Usage: " << av[0] << " [sequence of numbers to sort]\n";
		return 1;
	}

	// std::vector<int> test_sequence = {11,2,17,0,16,8,6,15,10,3,21,1,18,9,14,19,12,5,4,20,13,7};
	// std::vector<int> test_sequence = {30,49,60,1,31,29,42,46,13,8,5};

	printf("\nPmergeme Version 1.23423b\n\n");
	std::cout << "Original sequence: ";
	for (auto i: test_sequence)
		std::cout << i << ' ';
	std::cout << "\n\n";
	ford_johnson(test_sequence, 1);
}

#else
int main ()
{
	auto jacob = {1,4,5,7,9};
	for (auto i : jacob)
		std::cout << i << " ";
	std::cout << "\n";

	auto it = std::lower_bound(jacob.begin(), jacob.begin() + 2, 6);
	std::cout << *it;
}
#endif
