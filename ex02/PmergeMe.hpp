#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <ctime>
#include <sstream>

int checking(int argc, char **argv);

class PmergeMe {
	private:
		std::vector<int> _vec;
		std::deque<int>  _deq;
		void mergeInsertVec(std::vector<int> &v);
		void mergeInsertDeq(std::deque<int> &d);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();
		void fill(int argc, char **argv);
		void sort();
};
