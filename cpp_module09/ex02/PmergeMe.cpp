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

void PmergeMe::merge(int left, int mid, int right) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1);
    std::vector<int> R(n2);
    for (int i = 0; i < n1; i++) 
        L[i] = mainChain[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = mainChain[mid + 1 + i];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) 
	{
        if (L[i] <= R[j]) 
		{
            mainChain[k] = L[i];
            i++;
        } else 
		{
            mainChain[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) 
	{
        mainChain[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) 
	{
        mainChain[k] = R[j];
        j++;
        k++;
    }
}

void PmergeMe::mergeSort(int left, int right) 
{
	if (left < right) 
	{
        int mid = left + (right - left) / 2;

        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}

void PmergeMe::makeMainChain()
{
	std::size_t i;
	for (i = 0; i < inputData.size(); i += 2)
	{
		std::cout << inputData[i] << std::endl;
		if (!inputData[i + 1])
		{
			otherChain.push_back(inputData[i]);
			break;
		}
		mainChain.push_back(inputData[i]);
		otherChain.push_back(inputData[i + 1]);
	}
	mergeSort(0, mainChain.size() - 1);
}

int PmergeMe::insert_element(int element)
{
    int left = 0;
    int right = mainChain.size() - 1;
    while (left <= right)
	{
        int mid = (left + right) / 2;
        if (element < mainChain[mid])
            right = mid - 1;
		else
            left = mid + 1;
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
	std::size_t jacobsthalNum = 0;
	std::size_t prevJacobsthal = 0;
	int n = 0;

	int index = insert_element(mainChain, otherChain[0]);
	mainChain.insert(mainChain.begin() + index, otherChain[0]);
	numbersOfinsert++;
	while (1)
	{
		prevJacobsthal = jacobsthalNum;
		jacobsthalNum = jacobsthal(n);

		std::cout << "prev : " << prevJacobsthal << std::endl;
		std::cout << "jacobsthalNum : " << jacobsthalNum << std::endl;

		for (std::size_t i = jacobsthalNum; i != prevJacobsthal; i--)
		{
			if (numbersOfinsert >= otherChain.size())
				break ;
			if (i > otherChain.size() - 1)
				i = otherChain.size() - 1;
			std::cout << "index : " << i << std::endl;

			index = insert_element(mainChain, otherChain[i]);
        	mainChain.insert(mainChain.begin() + index, otherChain[i]);
			
			std::cout << otherChain[i] << std::endl;
			std::cout << "numbersof : " << numbersOfinsert << std::endl;

			numbersOfinsert++;
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
	std::cout << "mainChain : ";
	for (std::size_t i = 0; i < mainChain.size(); i++)
		std::cout << mainChain[i] << " ";
	std::cout << std::endl;
	std::cout << "otherChain : ";
	for (std::size_t i = 0; i < otherChain.size(); i++)
		std::cout << otherChain[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::printInputDataValue()
{
	for (std::size_t i = 0; i < inputData.size(); i++)
		std::cout << inputData[i] << " ";
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
	printInputDataValue();
	vectorSort();
	//dequeSort();
}