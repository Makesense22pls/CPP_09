#include "PmergeMe.hpp"

int main(int argc, char **argv){

	if (checking(argc, argv) == 1)
		return (1);
	else
	{
		PmergeMe pmerge;
		pmerge.fill(argc, argv);
		pmerge.sort();
	}
	return (0);
}
