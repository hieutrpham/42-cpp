#pragma once

#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <chrono>

class PmergeMe {
private:
	std::vector<int> jacobsthal = {3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525};
public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe&);
	PmergeMe&        operator=(const PmergeMe&);
	int              get_pair_index(int first, std::list<std::pair<int, int>> &pairs, std::list<int> &main_chain);
	int              get_pair_index(int first, std::vector<std::pair<int, int>> &pairs, std::vector<int> &main_chain);
	std::list<int>   jacob_gen_list(size_t pend_size);
	std::vector<int> jacob_gen_vect(size_t pend_size);
	void             ford_johnson(std::list<int> &v);
	void             ford_johnson(std::vector<int> &v);
};
