#include "PmergeMe.hpp"

int	stringToInt(std::string string)
{
	std::stringstream stream;
	int integer;

	stream << string;
	stream >> integer;
	return integer;
}

int checkInput(std::string argv)
{
	for (int i = 0; i < argv.size(); i++)
	{
		if (!(argv >= "0" && argv <= "9"))
			throw std::exception();
	}
	return stringToInt(argv);
}

int main (int argc, char **argv)
{
	try
	{
		std::vector<int> inputData;

		if (argc < 2)
			throw std::exception();
		for (int i = 1; i < argc; i ++)
			inputData.push_back(checkInput(argv[i]));
		PmergeMe pmergeMe(inputData);
		pmergeMe.executePmergeMe();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}