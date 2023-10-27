#include "PmergeMe.hpp"

int main (int argc, char **argv)
{
	try
	{
		std::vector<int> inputData;

		if (argc < 2)
			throw std::exception();
		for (int i = 0; i < argc; i ++)
		{
			inputData.push(checkInput());
		}
		PmergeMe pmergeMe();
		PmergeMe.executePmergeMe());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}