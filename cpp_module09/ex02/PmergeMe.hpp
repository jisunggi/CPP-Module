#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>

class PmergeMe
{
	private :
		PmergeMe();

    public :
        PmergeMe();
        ~PmergeMe();
		PmergeMe(const PmergeMe &pmergeMe);
		PmergeMe &operator=(const PmergeMe &pmergeMe);

		void executePmergeMe(std::string input);

};

#endif