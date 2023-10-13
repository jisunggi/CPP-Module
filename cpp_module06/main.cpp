#include "ScalarConverter.hpp"

int	stringToInt(std::string string)
{
	std::stringstream stream;
	int integer;

	stream << string;
	stream >> integer;
	if (stream.fail())
		std::cout << "overflow" << std::endl;
	return integer;
}

float stringToFloat(std::string string)
{
	std::stringstream stream;
	float rtnFloat;

	stream << string;
	stream >> rtnFloat;
	if (stream.fail())
		std::cout << "overflow" << std::endl;
	return rtnFloat;
}

double stringToDouble(std::string string)
{
	std::stringstream stream;
	double rtnDouble;

	stream << string;
	stream >> rtnDouble;
	if (stream.fail())
		std::cout << "overflow" << std::endl;
	return rtnDouble;
}


int main (int argc, char **argv)
{
	if (argc < 2)
		return 1;

	std::string str(argv[1]);
	ScalarConverter::convert(str);
}