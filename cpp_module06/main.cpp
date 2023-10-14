#include "ScalarConverter.hpp"

int	ScalarConverter::stringToInt(std::string string)
{
	std::stringstream stream;
	int integer;

	stream << string;
	stream >> integer;
	if (stream.fail())
	{
		dataType = "double";
		error = 1;
	}
	return integer;
}

float ScalarConverter::stringToFloat(std::string string)
{
	std::stringstream stream;
	float rtnFloat;

	stream << string;
	stream >> rtnFloat;
	if (stream.fail())
		return error = 1;
	std::cout << rtnFloat << std::endl;
	return rtnFloat;
}

double ScalarConverter::stringToDouble(std::string string)
{
	std::stringstream stream;
	double rtnDouble;

	stream << string;
	stream >> rtnDouble;
	if (stream.fail())
		return error = 1;
	return rtnDouble;
}


int main (int argc, char **argv)
{
	if (argc < 2)
		return 1;

	std::string str(argv[1]);
	ScalarConverter::convert(str);
}