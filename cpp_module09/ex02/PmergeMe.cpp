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

// void PmergeMe::mergeSort(int left, int right)
// {
// 	if (left < right)
// }

void PmergeMe::makeMainChain()
{
	for (int i = 0; i < inputData.size(); i += 2)
	{
		if (inputData[i] > inputData[i + 1])
		{
			mainChain.push_back(inputData[i]);
			otherChain.push_back(inputData[i + 1]);
		}
		else
		{
			mainChain.push_back(inputData[i + 1]);
			otherChain.push_back(inputData[i]);
		}
	}
	std::cout << mainChain.size() << std::endl;
	std::cout << otherChain.size() << std::endl;
	std::vector<int>::iterator iter;
	iter = mainChain.begin();
	while (iter != mainChain.end())
	{
		std::cout << *iter << std::endl;
		iter++;
	}
	// for (int i = 0; mainChain[i]; i++)
	// 	std::cout << mainChain[i] << " ";
	// std::cout << std::endl;
	// for (int i = 0; otherChain[i]; i++)
	// 	std::cout << otherChain[i] << " ";
	// std::cout << std::endl;
	//mainChainSort();
}

void PmergeMe::mergeInsertionSort()
{
	//mergeSort(0, inputData.size() - 1);

	makeMainChain();

}

// void printsortedValue()
// {}

void PmergeMe::vectorSort()
{
	//start ;
	mergeInsertionSort();
	//end ;
	//printsortedValue();
	//std::cout;
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

	vectorSort();
	//dequeSort();
}