#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>

class PmergeMe
{
	private :
		PmergeMe();
		std::vector<int> inputData;

    public :
        PmergeMe(std::vector<int> inputData);
        ~PmergeMe();
		PmergeMe(const PmergeMe &pmergeMe);
		PmergeMe &operator=(const PmergeMe &pmergeMe);

		void executePmergeMe();

};

#endif