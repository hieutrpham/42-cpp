#include "PMergeMe.hpp" 

PMergeMe::PMergeMe(){}

PMergeMe::PMergeMe(const PMergeMe& ){}

PMergeMe& PMergeMe::operator=(const PMergeMe& ){return *this;}

PMergeMe::~PMergeMe(){}

std::vector<size_t> PMergeMe::_generateJacobsthalOrder(size_t Size){
    std::vector<size_t> order;
    if (Size == 0) return order;
    if (Size == 1) {
        order.push_back(0);
        return order;
    }

    // Generate Jacobsthal : J0 =0; J1 = 1; Jn = Jn-1 + 2*Jn-2
    // examples: size is 20
    std::vector<size_t> jac;
    jac.push_back(0);
    jac.push_back(1);
    while (jac.back() < Size){
        size_t next = jac[jac.size() -1] + 2 * jac[jac.size() -2];
        jac.push_back(next);
    }
    // after loop, jac will be [0,1,1,3,5,11,21]. It stop wwhen next is 21.

    // Add Jacobsthal numbers (starting from the second 1, i.e., index 2)
    // k run from 2 until 6 due to size of jac is 7
    // idx will have value is  1,3,5,11
    for (size_t k = 2; k < jac.size(); ++k){
        size_t idx = jac[k];
        if (idx >= Size) break;
        if (idx != 0){
            order.push_back(idx);
        }
    }
    // order will have value is [1,3,5,11]

    // Mark which indices are already used
    std::vector<bool> used(Size, false);
    for (size_t i = 0 ; i < order.size(); ++i){
        used[order[i]] = true;
    }
    // used[1] = used[3] = used[5] = used[11] = True

    // Append the rest in natural order
    for (size_t i = 0; i < Size; ++i){
        if (!used[i]){
            order.push_back(i);
        }
    }
    // order will have value[1,3,5,11,0,2,4,6,7,8,9,10,12...19]
    return order;
}

void PMergeMe::_fordJohnsonVector(std::vector<int>& cont){
    if (cont.size() <= 1) return;

    std::vector<std::pair<int, int> > pairs;
    int straggler = -1;
    size_t i = 0;
    // seperate to pairs
    for (; i + 1 < cont.size(); i +=2){
        int a = cont[i];
        int b = cont[i + 1];
        if (a >= b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }
    if (i < cont.size())
        straggler = cont[i];

    // push back to main and pend
    std::vector<int> main, pend;
    for (size_t j = 0; j < pairs.size(); ++j){
        main.push_back(pairs[j].first);
        pend.push_back(pairs[j].second);
    }
    // sorted for main
    _fordJohnsonVector(main);

    std::vector<int> sorted = main;
    //find the Jacobsthal order
    std::vector<size_t> order = _generateJacobsthalOrder(pend.size());

    // insert from pend to sorted
    for (size_t k = 0; k < order.size(); ++k){
        int val = pend[order[k]];
        std::vector<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), val);
        sorted.insert(it, val);
    }

    if (straggler != -1){
        std::vector<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), straggler);
        sorted.insert(it, straggler);
    }

    cont = sorted;
}

void PMergeMe::_fordJohnsonDeque(std::deque<int>& cont){
    if (cont.size() <= 1) return;

    std::vector<std::pair<int, int> > pairs;
    int straggler = -1;
    size_t i = 0;
    // seperate to pairs
    for (; i + 1 < cont.size(); i +=2){
        int a = cont[i];
        int b = cont[i + 1];
        if (a >= b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }
    if (i < cont.size())
        straggler = cont[i];

    // push back to main and pend
    std::deque<int> main, pend;
    for (size_t j = 0; j < pairs.size(); ++j){
        main.push_back(pairs[j].first);
        pend.push_back(pairs[j].second);
    }
    // sorted for main
    _fordJohnsonDeque(main);
    std::deque<int> sorted = main;
    //find the Jacobsthal order
    std::vector<size_t> order = _generateJacobsthalOrder(pend.size());

    // insert from pend to sorted
    for (size_t k = 0; k < order.size(); ++k){
        int val = pend[order[k]];
        std::deque<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), val);
        sorted.insert(it, val);
    }

    if (straggler != -1){
        std::deque<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), straggler);
        sorted.insert(it, straggler);
    }

    cont = sorted;
}

void PMergeMe::sortVector(std::vector<int>& container){
    _fordJohnsonVector(container);
}

void PMergeMe::sortDeque(std::deque<int>& container){
    _fordJohnsonDeque(container);
}
