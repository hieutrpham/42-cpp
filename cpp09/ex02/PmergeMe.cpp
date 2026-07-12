#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) : jacobsthal(other.jacobsthal) {}
PmergeMe& PmergeMe::operator=(const PmergeMe& other){
	if (this != &other)
		jacobsthal = other.jacobsthal;
	return *this;
}

int PmergeMe::get_pair_index(int first, std::list<std::pair<int, int>> &pairs, std::list<int> &main_chain)
{
	int index = -1;
	int second = -1;

	for (auto it = pairs.begin(); it != pairs.end(); ++it)
	{
		if (first == (*it).first)
			second = (*it).second;
	}

	int j = 0;
	for (auto it = main_chain.begin(); it != main_chain.end(); ++it)
	{
		if (second == *it)
			index = j;
		j++;
	}

	return index;
}

int PmergeMe::get_pair_index(int first, std::vector<std::pair<int, int>> &pairs, std::vector<int> &main_chain)
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

std::list<int> PmergeMe::jacob_gen_list(size_t pend_size)
{
	std::list<int> jacob_index = {};

	int x = 0;

	for (size_t i = 0; i < jacobsthal.size(); ++i)
	{
		x = jacobsthal[i];
		while (x > 1 && jacob_index.size() < pend_size)
		{
			if (std::find(jacob_index.begin(), jacob_index.end(), x) == jacob_index.end())
				jacob_index.emplace_back(x);
			x--;
		}
	}

	return jacob_index;
}

std::vector<int> PmergeMe::jacob_gen_vect(size_t pend_size)
{
	std::vector<int> jacob_index = {};

	int x = 0;

	for (size_t i = 0; i < jacobsthal.size(); ++i)
	{
		x = jacobsthal[i];
		while (x > 1 && jacob_index.size() < pend_size)
		{
			if (std::find(jacob_index.begin(), jacob_index.end(), x) == jacob_index.end())
				jacob_index.emplace_back(x);
			x--;
		}
	}

	return jacob_index;
}

// reference: https://medium.com/@mohammad.ali.ibrahim.525/ford-johnson-algorithm-merge-insertion-4b024f0c3d42
void PmergeMe::ford_johnson(std::list<int> &v)
{
	if (v.size() <= 1)
		return;

	// break sequence into sorted pairs
	std::list<std::pair<int, int>> pairs;
	for (size_t i = 0; i + 1 < v.size(); i += 2)
	{
		int a = *std::next(v.begin(), i);
		int b = *std::next(v.begin(), i + 1);
		if (a >= b)
			pairs.emplace_back(std::make_pair(b, a));
		else
			pairs.emplace_back(std::make_pair(a, b));
	}

	// initialize main and pend chain
	std::list<int> main_chain, pend_chain;

	for (auto it = pairs.begin(); it != pairs.end(); ++it)
	{
		main_chain.emplace_back((*it).second);
		pend_chain.emplace_back((*it).first);
	}

	// if there are left over numbers, append to pend chain
	if (v.size() % 2)
	{
		pend_chain.emplace_back(v.back());
	}

	// NOTE: recurse on main_chain
	ford_johnson(main_chain);

	// aligning new pend to the new main
	std::list<int> new_pend;

	for (auto i = main_chain.begin(); i != main_chain.end(); ++i)
	{
		for (auto j = pairs.begin(); j != pairs.end(); ++j)
		{
			if (*i == (*j).second)
				new_pend.emplace_back((*j).first);
		}
	}

	std::list<int> jacob = jacob_gen_list(new_pend.size());

	if (pend_chain.size() > new_pend.size())
		new_pend.emplace_back(pend_chain.back());

	// insert the first number from pend
	main_chain.insert(main_chain.begin(), new_pend.front());

	// insert based on the jacob sequence
	for (size_t i = 0; i < jacob.size(); ++i)
	{
		size_t index = *std::next(jacob.begin(), i) - 1;
		auto it = std::next(new_pend.begin(), index);
		if (index < new_pend.size())
		{
			auto main_index = get_pair_index(*it, pairs, main_chain);
			if (main_index > 0)
			{
				auto new_pend_it = std::next(new_pend.begin(), index);
				auto it = std::lower_bound(main_chain.begin(), std::next(main_chain.begin(), main_index), *new_pend_it);
				main_chain.insert(it, *new_pend_it);
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

	// realigned main_chain from previous recursion level to the sorted one
	v = main_chain;
}

void PmergeMe::ford_johnson(std::vector<int> &v)
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
			pairs.emplace_back(std::make_pair(b, a));
		else
			pairs.emplace_back(std::make_pair(a, b));
	}
	
	// initialize main and pend chain
	std::vector<int> main_chain, pend_chain;

	size_t pair_i = 0;
	for (; pair_i < pairs.size(); ++pair_i)
	{
		main_chain.emplace_back(pairs[pair_i].second);
		pend_chain.emplace_back(pairs[pair_i].first);
	}

	// if there are left over numbers, append to pend chain
	if (v.size() % 2)
	{
		pend_chain.emplace_back(v[pair_i * 2]);
	}

	// NOTE: recurse on main_chain
	ford_johnson(main_chain);

	// aligning new pend to the new main
	std::vector<int> new_pend;
	for (size_t i = 0; i < main_chain.size(); ++i)
	{
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (main_chain[i] == pairs[j].second)
				new_pend.emplace_back(pairs[j].first);
		}
	}

	std::vector<int> jacob = jacob_gen_vect(new_pend.size());

	if (pend_chain.size() > new_pend.size())
		new_pend.emplace_back(pend_chain.back());

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

	// realigned main_chain from previous recursion level to the sorted one
	v = main_chain;
}
