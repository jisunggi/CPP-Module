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

    std::vector<int> leftArray(n1);
    std::vector<int> rightArray(n2);
    for (int i = 0; i < n1; i++) 
        leftArray[i] = mainChain[left + i];
    for (int i = 0; i < n2; i++)
        rightArray[i] = mainChain[mid + 1 + i];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) 
	{
        if (leftArray[i] <= rightArray[j]) 
		{
            mainChain[k] = leftArray[i];
            i++;
        }
		else 
		{
            mainChain[k] = rightArray[j];
            j++;
        }
        k++;
    }
    while (i < n1) 
	{
        mainChain[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < n2) 
	{
        mainChain[k] = rightArray[j];
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

int PmergeMe::insertElement(int element)
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

	int index = insertElement(otherChain[0]);
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

			index = insertElement(otherChain[i]);
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

void PmergeMe::dequeMerge(int left, int mid, int right) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> leftArray(n1);
    std::vector<int> rightArray(n2);
    for (int i = 0; i < n1; i++) 
        leftArray[i] = mainChainDeque[left + i];
    for (int i = 0; i < n2; i++)
        rightArray[i] = mainChainDeque[mid + 1 + i];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) 
	{
        if (leftArray[i] <= rightArray[j]) 
		{
            mainChainDeque[k] = leftArray[i];
            i++;
        }
		else 
		{
            mainChainDeque[k] = rightArray[j];
            j++;
        }
        k++;
    }
    while (i < n1) 
	{
        mainChainDeque[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < n2) 
	{
        mainChainDeque[k] = rightArray[j];
        j++;
        k++;
    }
}

void PmergeMe::dequeMergeSort(int left, int right) 
{
	if (left < right) 
	{
        int mid = left + (right - left) / 2;

        dequeMergeSort(left, mid);
        dequeMergeSort(mid + 1, right);
        dequeMerge(left, mid, right);
    }
}

void PmergeMe::dequeMakemainChain()
{
	std::size_t i;
	for (i = 0; i < inputData.size(); i += 2)
	{
		std::cout << inputData[i] << std::endl;
		if (!inputData[i + 1])
		{
			otherChainDeque.push_back(inputData[i]);
			break;
		}
		mainChainDeque.push_back(inputData[i]);
		otherChainDeque.push_back(inputData[i + 1]);
	}
	dequeMergeSort(0, mainChainDeque.size() - 1);
}

int PmergeMe::dequeInsertElement(int element)
{
    int left = 0;
    int right = mainChainDeque.size() - 1;
    while (left <= right)
	{
        int mid = (left + right) / 2;
        if (element < mainChainDeque[mid])
            right = mid - 1;
		else
            left = mid + 1;
    }
    return left;
}

void PmergeMe::dequeInsertionSort()
{
	std::size_t numbersOfinsert = 0;
	std::size_t jacobsthalNum = 0;
	std::size_t prevJacobsthal = 0;
	int n = 0;

	int index = dequeInsertElement(otherChainDeque[0]);
	mainChainDeque.insert(mainChainDeque.begin() + index, otherChainDeque[0]);
	numbersOfinsert++;
	while (1)
	{
		prevJacobsthal = jacobsthalNum;
		jacobsthalNum = jacobsthal(n);

		std::cout << "prev : " << prevJacobsthal << std::endl;
		std::cout << "jacobsthalNum : " << jacobsthalNum << std::endl;

		for (std::size_t i = jacobsthalNum; i != prevJacobsthal; i--)
		{
			if (numbersOfinsert >= otherChainDeque.size())
				break ;
			if (i > otherChainDeque.size() - 1)
				i = otherChainDeque.size() - 1;
			std::cout << "index : " << i << std::endl;

			index = dequeInsertElement(otherChainDeque[i]);
        	mainChainDeque.insert(mainChainDeque.begin() + index, otherChainDeque[i]);
			
			std::cout << otherChainDeque[i] << std::endl;
			std::cout << "numbersof : " << numbersOfinsert << std::endl;

			numbersOfinsert++;
		}
		if (numbersOfinsert >= otherChainDeque.size())
			break ;
		n++;
	}
}

void PmergeMe::dequeMergeInsertionSort()
{
	dequeMakemainChain();
	dequeInsertionSort();
}

void PmergeMe::printsortedValue()
{
	std::cout << "mainChain : ";
	for (std::size_t i = 0; i < mainChainDeque.size(); i++)
		std::cout << mainChainDeque[i] << " ";
	std::cout << std::endl;
	std::cout << "otherChain : ";
	for (std::size_t i = 0; i < otherChainDeque.size(); i++)
		std::cout << otherChainDeque[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::printInputDataValue()
{
	for (std::size_t i = 0; i < inputData.size(); i++)
		std::cout << inputData[i] << " ";
}

void PmergeMe::vectorSort()
{
	clock_t start = clock();
	mergeInsertionSort();
	clock_t end = clock();
	//printsortedValue();
	std::cout << "Time to process a range of " << std::setw(4) << mainChain.size() << " elements with std::vector : " << end - start << "ms" << std::endl;
}

void PmergeMe::dequeSort()
{
	clock_t start = clock();
	mergeInsertionSort();
	clock_t end = clock();
	printsortedValue();
	std::cout << "Time to process a range of " << std::setw(4) << mainChainDeque.size() << " elements with std::deaue : " << end - start << "ms" << std::endl;
}

void PmergeMe::executePmergeMe()
{
	printInputDataValue();
	vectorSort();
	dequeSort();
}