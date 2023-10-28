#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <sstream>
#include <iterator>
#include <iomanip>

class PmergeMe
{
	private :
		PmergeMe();
		std::vector<int> inputData;
		std::vector<int> mainChain;
		std::vector<int> otherChain;
		std::deque<int> mainChainDeque;
		std::deque<int> otherChainDeque;

    public :
        PmergeMe(std::vector<int> inputData);
        ~PmergeMe();
		PmergeMe(const PmergeMe &pmergeMe);
		PmergeMe &operator=(const PmergeMe &pmergeMe);

		void printsortedValue();
		void printInputDataValue();

		void executePmergeMe();
		
		void vectorSort();
		void mergeInsertionSort();
		void makeMainChain();

		void merge(int left, int mid, int right);
		void mergeSort(int left, int right);

		int insertElement(int element);
		void insertionSort();
		int jacobsthal(int n);

		void dequeSort();
		void dequeMergeInsertionSort();
		void dequeMakemainChain();

		void dequeMergeSort(int left, int right);
		void dequeMerge(int left, int mid, int right);

		int dequeInsertElement(int element);
		void dequeInsertionSort();

};

#endif