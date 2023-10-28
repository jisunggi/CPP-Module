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

// Binary search for insertion
int PmergeMe::binarySearch(const std::vector<int>& arr, int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

// Insertion sort with binary search for the "main Chain"
void PmergeMe::insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Change the comparison to ascending order
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
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
		mainChain.push_back(inputData[i]);
		otherChain.push_back(inputData[i + 1]);
	}
	if (!inputData[i])
		otherChain.push_back(inputData[i]);


}

void PmergeMe::mergeInsertionSort()
{
	//mergeSort(0, inputData.size() - 1);
	makeMainChain();
	//insertionSort();
	insertionSort(otherChain); // Step 4: Insertion Sort for other Chain

    // Merge the main and other chains
    std::size_t i = 0, j = 0;
    while (i < mainChain.size() && j < otherChain.size()) {
        if (mainChain[i] >= otherChain[j]) {
            inputData[i + j] = mainChain[i];
            i++;
        } else {
            inputData[i + j] = otherChain[j];
            j++;
        }
    }

    while (i < mainChain.size()) {
        inputData[i + j] = mainChain[i];
        i++;
    }

    while (j < otherChain.size()) {
        inputData[i + j] = otherChain[j];
        j++;
    }
}

void PmergeMe::printsortedValue()
{
	std::vector<int>::iterator iter;
	iter = inputData.begin();
	while (iter != inputData.end())
	{
		std::cout << *iter << std::endl;
		iter++;
	}

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