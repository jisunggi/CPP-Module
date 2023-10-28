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
		mainChain.push_back(inputData[i]);
		otherChain.push_back(inputData[i + 1]);
	}
	if (inputData[i])
		otherChain.push_back(inputData[i]);


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

void PmergeMe::mergeInsertionSort()
{
	//mergeSort(0, inputData.size() - 1);
	makeMainChain();
	//insertionSort();
	std::size_t i;
	for (i = 0; i < otherChain.size(); i++) {
        int index = insert_element(mainChain, otherChain[i]);
        mainChain.insert(mainChain.begin() + index, otherChain[i]);
    }
	
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
	for (int i = 0; mainChain[i]; i++)
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