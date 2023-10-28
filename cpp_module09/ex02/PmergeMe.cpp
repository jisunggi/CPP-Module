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

void PmergeMe::makeMainChain()
{
	int temp;
	for (std::size_t i = 0; i < inputData.size(); i += 2)
	{
		if (inputData[i] < inputData[i + 1])
		{
			temp = inputData[i + 1];
			inputData[i + 1] = inputData[i];
			inputData[i] = temp;
		}
	}
  	
	int mainChainTemp, otherChainTemp;
	for (std::size_t i = 0; i < inputData.size(); i += 2)
	{
    	for(std::size_t j = i; j < inputData.size(); j += 2)
		{
			if (!inputData[j + 3])
				break;
      		if (inputData[j] > inputData[j + 2])
			{
        		mainChainTemp = inputData[j + 2];
				otherChainTemp = inputData[j + 3];
        		inputData[j + 2]  = inputData[j];
        		inputData[j + 3] = inputData[j + 1];
				inputData[j] = mainChainTemp;
				inputData[j + 1] = otherChainTemp;
      		}
    	}
  	}

	std::size_t i;
	for (i = 0; i < inputData.size(); i += 2)
	{
		if (!inputData[i + 1])
		{
			otherChain.push_back(inputData[i]);
			break;
		}
		mainChain.push_back(inputData[i]);
		otherChain.push_back(inputData[i + 1]);
	}
}

int insert_element(std::vector<int>& mainChain, int element) {
    int left = 0;
    int right = mainChain.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (element < mainChain[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int PmergeMe::jacobsthal(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

void PmergeMe::insertionSort()
{
	std::size_t numbersOfinsert = 0;
	int n = 0;
	int jacobsthalNum = 0;
	int prevJacobsthal = 0;

	int index = insert_element(mainChain, otherChain[0]);
	mainChain.insert(mainChain.begin() + index, otherChain[0]);
	numbersOfinsert++;
	while (1)
	{
		prevJacobsthal = jacobsthalNum;
		jacobsthalNum = jacobsthal(n);
		std::cout << "jacobsthalNum : " << jacobsthalNum << std::endl;
		std::cout << "prev : " << jacobsthalNum << std::endl;

		for (int i = jacobsthalNum; i != prevJacobsthal; i--)
		{
			std::cout << "index : " << i << std::endl;
			index = insert_element(mainChain, otherChain[i]);
        	mainChain.insert(mainChain.begin() + index, otherChain[i]);
			std::cout << otherChain[i] << i << std::endl;
			numbersOfinsert++;
			std::cout << "numbersof : " << numbersOfinsert << std::endl;
			if (numbersOfinsert >= otherChain.size())
				break ;
		}
		if (numbersOfinsert >= otherChain.size())
			break ;
		n++;
	}
}

void PmergeMe::mergeInsertionSort()
{
	makeMainChain();
	insertionSort();
}

void PmergeMe::printsortedValue()
{
	// std::vector<int>::iterator iter;
	// iter = inputData.begin();
	// while (iter != inputData.end())
	// {
	// 	std::cout << *iter << std::endl;
	// 	iter++;
	// }

	std::cout << "mainChain : ";
	for (std::size_t i; i < mainChain.size(); i++)
		std::cout << mainChain[i] << " ";
	std::cout << std::endl;
	for (int i = 0; otherChain[i]; i++)
		std::cout << otherChain[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::vectorSort()
{
	//start ;
	mergeInsertionSort();
	//end ;
	printsortedValue();
	//std::cout;
}

void PmergeMe::executePmergeMe()
{
	vectorSort();
}