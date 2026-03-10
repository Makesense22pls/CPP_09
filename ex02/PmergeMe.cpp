#include "PmergeMe.hpp"

//FORME CANONIQUE
PmergeMe::PmergeMe(){};

PmergeMe::PmergeMe(const PmergeMe &other){
	*this = other;
};

PmergeMe &PmergeMe::operator=(const PmergeMe &other){
	if (this != &other)
	{
		this->_vec = other._vec;
		this->_deq = other._deq;
	}
	return *this;
}
PmergeMe::~PmergeMe(){};

int checking(int argc, char **argv){
	if (argc < 2)
		return(std::cerr << "Error: not enough arguments" << std::endl, 1);
	for (int i = 1; i < argc; i++)
	{
		std::string token(argv[i]);
		if (token.empty())
			return(std::cerr << "Error" << std::endl, 1);
		for (size_t j = 0; j < token.length(); j++)
		{
			if (token[j] < '0' || token[j] > '9')
				return(std::cerr << "Error" << std::endl, 1);
		}
		std::istringstream ss(token);
		long n;
		ss >> n;
		if (n <= 0)
			return(std::cerr << "Error" << std::endl, 1);
	}
	return (0);
}

void PmergeMe::fill(int argc, char **argv)
{
	int i = 1;
	while(i < argc)
	{
		std::istringstream ss(argv[i]);
		int n;
		ss >> n;
		_vec.push_back(n);
		_deq.push_back(n);
		i++;
	}
}

static std::vector<int> buildJacobsthal(int n)
{
	std::vector<int> jac;
	jac.push_back(0);
	jac.push_back(1);
	while (true)
	{
		int next = jac[jac.size() - 1] + 2 * jac[jac.size() - 2];
		if (next >= n)
			break ;
		jac.push_back(next);
	}
	return (jac);
}

//VECTORRRRRR
std::vector<std::pair<int,int> > makePairs(const std::vector<int> &v)
{
	std::vector<std::pair<int,int> > pairs;
	for (size_t i = 0; i + 1 < v.size(); i += 2)
	{
		int a = v[i], b = v[i + 1];
		if (a < b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
	}
	return (pairs);
}

std::vector<int> getSmalls(const std::vector<int> &largers, const std::vector<std::pair<int,int> > &pairs)
{
	std::vector<int> smalls;
	for (size_t i = 0; i < largers.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (pairs[j].first == largers[i])
			{
				smalls.push_back(pairs[j].second);
				break ;
			}
		}
	}
	return (smalls);
}

std::vector<int> buildmain(const std::vector<int> &largers, const std::vector<int> &smalls)
{
	std::vector<int> main;
	main.push_back(smalls[0]);
	for (size_t i = 0; i < largers.size(); i++)
		main.push_back(largers[i]);
	return (main);
}

void insertPending(std::vector<int> &main, const std::vector<int> &pending)
{
	std::vector<int> jac = buildJacobsthal((int)pending.size());
	std::vector<bool> inserted(pending.size(), false);

	for (size_t k = 2; k < jac.size(); k++)
    {
		int idx = jac[k] - 1;
		if (idx >= (int)pending.size())
		    idx = (int)pending.size() - 1;
		for (int m = idx; m >= 0; m--)
		{
			if (inserted[m])
				continue ;
			std::vector<int>::iterator pos = std::lower_bound(main.begin(), main.end(), pending[m]);
			main.insert(pos, pending[m]);
			inserted[m] = true;
		}
	}
	for (size_t m = 0; m < pending.size(); m++)
	{
		if (!inserted[m])
		{
			std::vector<int>::iterator pos = std::lower_bound(main.begin(), main.end(), pending[m]);
			main.insert(pos, pending[m]);
		}
	}
}

void PmergeMe::mergeInsertVec(std::vector<int> &v)
{
	if (v.size() <= 1)
		return ;
	bool hasLeftover = (v.size() % 2 != 0);
	int leftover = 0;
	if (hasLeftover)
		leftover = v.back();
	std::vector<std::pair<int,int> > pairs = makePairs(v);
	std::vector<int> largers;
	for (size_t i = 0; i < pairs.size(); i++)
		largers.push_back(pairs[i].first);
	mergeInsertVec(largers);

	std::vector<int> smalls = getSmalls(largers, pairs);
	std::vector<int> main = buildmain(largers, smalls);

	std::vector<int> pending(smalls.begin() + 1, smalls.end());
	if (hasLeftover)
		pending.push_back(leftover);

	insertPending(main, pending);
	v = main;
}

static std::deque<int> buildJacobsthalDeq(int n)
{
	std::deque<int> jac;
	jac.push_back(0);
	jac.push_back(1);
	while (true)
	{
		int next = jac[jac.size() - 1] + 2 * jac[jac.size() - 2];
		if (next >= n)
			break ;
		jac.push_back(next);
	}
	return (jac);
}

std::deque<std::pair<int,int> > makepairsdeque(const std::deque<int> &d)
{
	std::deque<std::pair<int,int> > pairs;
	for (size_t i = 0; i + 1 < d.size(); i += 2)
	{
		int a = d[i], b = d[i + 1];
		if (a < b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
	}
	return (pairs);
}

std::deque<int> getSmallsDeq(const std::deque<int> &largers, const std::deque<std::pair<int,int> > &pairs)
{
	std::deque<int> smalls;
	for (size_t i = 0; i < largers.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (pairs[j].first == largers[i])
			{
				smalls.push_back(pairs[j].second);
				break ;
			}
		}
	}
	return (smalls);
}

std::deque<int> buildmainDeq(const std::deque<int> &largers, const std::deque<int> &smalls)
{
	std::deque<int> main;
	main.push_back(smalls[0]);
	for (size_t i = 0; i < largers.size(); i++)
		main.push_back(largers[i]);
	return (main);
}

void insertPendingDeq(std::deque<int> &main, const std::deque<int> &pending)
{
	std::deque<int> jac = buildJacobsthalDeq((int)pending.size());
	std::deque<bool> inserted(pending.size(), false);

	for (size_t k = 2; k < jac.size(); k++)
	{
		int idx = jac[k] - 1;
		if (idx >= (int)pending.size())
			idx = (int)pending.size() - 1;
		for (int m = idx; m >= 0; m--)
		{
			if (inserted[m])
				continue ;
			std::deque<int>::iterator pos = std::lower_bound(main.begin(), main.end(), pending[m]);
			main.insert(pos, pending[m]);
			inserted[m] = true;
		}
	}
	for (size_t m = 0; m < pending.size(); m++)
	{
		if (!inserted[m])
		{
			std::deque<int>::iterator pos = std::lower_bound(main.begin(), main.end(), pending[m]);
			main.insert(pos, pending[m]);
		}
	}
}

//DEQUE ALGO
void PmergeMe::mergeInsertDeq(std::deque<int> &d)
{
	if (d.size() <= 1)
		return ;

	bool hasLeftover = (d.size() % 2 != 0);
	int leftover = 0;
	if (hasLeftover)
		leftover = d.back();

	std::deque<std::pair<int,int> > pairs = makepairsdeque(d);

	std::deque<int> largers;
	for (size_t i = 0; i < pairs.size(); i++)
		largers.push_back(pairs[i].first);
	mergeInsertDeq(largers);

	std::deque<int> smalls = getSmallsDeq(largers, pairs);
	std::deque<int> main = buildmainDeq(largers, smalls);

	std::deque<int> pending(smalls.begin() + 1, smalls.end());
	if (hasLeftover)
		pending.push_back(leftover);

	insertPendingDeq(main, pending);
	d = main;
}

void PmergeMe::sort()
{
	std::cout << "Before:";
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << " " << _vec[i];
	std::cout << std::endl;

	std::clock_t startVec = std::clock();
	mergeInsertVec(_vec);
	std::clock_t endVec = std::clock();

	std::clock_t startDeq = std::clock();
	mergeInsertDeq(_deq);
	std::clock_t endDeq = std::clock();

	std::cout << "After:";
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << " " << _vec[i];
	std::cout << std::endl;

	double timeVec = (double)(endVec - startVec) / CLOCKS_PER_SEC * 1000000.0;
	double timeDeq = (double)(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000.0;

	std::cout << "Time to process a range of " << _vec.size()
		<< " elements with std::vector : " << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size()
		<< " elements with std::deque  : " << timeDeq << " us" << std::endl;
}
