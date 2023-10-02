#include "ScalarConverter.cpp"

int	stringToInt(std::string string)
{
	std::stringstream stream;
	int integer;

	stream << string;
	stream >> integer;
	return integer;
}

int main (int argc, char **argv)
{
	std::string str(argv[1]);
	std::string dataType;
	static ScalarConverter scalarConverter();

	dataType = scalarConverter.checkDataType(argv[1]);
	scalarConverter.convert(str, dataType);
}