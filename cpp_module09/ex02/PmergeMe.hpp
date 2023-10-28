#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>

class PmergeMe
{
	private :
		PmergeMe();
		std::vector<int> inputData;
		std::vector<int> mainChain;
		std::vector<int> otherChain;

    public :
        PmergeMe(std::vector<int> inputData);
        ~PmergeMe();
		PmergeMe(const PmergeMe &pmergeMe);
		PmergeMe &operator=(const PmergeMe &pmergeMe);

		void executePmergeMe();
		void vectorSort();
		void printsortedValue();
		void mergeInsertionSort();
		void makeMainChain();

		int binarySearch(const std::vector<int>& arr, int left, int right, int key);
		void insertionSort(std::vector<int>& arr);
};

#endif