#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::vector<int> inputData)
{
	this->inputData = inputData;
}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &PmergeMe)
{
	(void)PmergeMe;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &PmergeMe)
{
	if (this != &PmergeMe)
	{
	}
    return *this;
}

void PmergeMe::executePmergeMe()
{
	std::vector<int>::iterator iter;
	iter = inputData.begin();
	while (iter != inputData.end())
	{
		std::cout << *iter << std::endl;
		iter++;
	}
}