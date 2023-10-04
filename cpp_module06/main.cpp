#include "ScalarConverter.hpp"

int	stringToInt(std::string string)
{
	std::stringstream stream;
	int integer;

	stream << string;
	stream >> integer;
	return integer;
}

float stringToFloat(std::string string)
{
	std::stringstream stream;
	float rtnFloat;

	stream << string;
	stream >> rtnFloat;
	return rtnFloat;
}

// std::string floatToString(float floatValue)
// {
// 	std::stringstream stream;
// 	std::string string;

// 	stream << floatValue;
// 	stream >> string;
// 	return string; 
// }

// int stringToFloat()
// {

// }


int main (int argc, char **argv)
{
	if (argc < 2)
		return 1;
	ScalarConverter scalarConverter;

	scalarConverter.checkDataType(argv[1]);
	std::string str(argv[1]);
	scalarConverter.convert(str);
	scalarConverter.printValue();
}