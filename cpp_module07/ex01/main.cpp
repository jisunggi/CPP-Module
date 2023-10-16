#include "iter.hpp"

template <typename T>
T print(const T &value)
{
	std::cout << value << std::endl;
	return value;
}

template <typename T>
T stringCut(T &value)
{
	value.resize(value.length() - 1);
	std::cout << value << std::endl;
	return value;
}

int main (void)
{
	int intArray[5] = {1, 2, 3, 4, 5};
	std::string array[3] = {"abc", "123", "test"};

	::iter(intArray, sizeof(intArray) / sizeof(*intArray), print<int>);
	::iter(array, sizeof(array) / sizeof(*array), stringCut<std::string>);
}