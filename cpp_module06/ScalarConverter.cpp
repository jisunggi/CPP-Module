#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter : Default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter : Constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter : Destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &scalarConverter)
{
	std::cout << "ScalarConverter : Copy constructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &scalarConverter)
{
	if (this != &scalarConverter)
	{
		
	}
	std::cout << "ScalarConverter : Copy assignment operator called" << std::endl;
	return *this;
}

std::string ScalarConverter::checkFloatOrDouble(char *argv)
{
	std::string dataType;

	for (idx = 0; argv[idx]; idx++)
	{
		if (argv[idx] == 'f')
			return dataType = "float";
	}
	return dataType = "double"
}

std::string ScalarConverter::checkDataType(char *argv)
{
	int idx = 0;
	std::string dataType;

	if (argv[idx] == "'" && argv[idx + 2] == "'")
		return dataType = "char";
	for (idx = 0; argv[idx]; idx++)
	{
		if (argv[idx] == '.')
			return dataType = checkFloatOrDouble(&argv[idx]);
	}
	return dataType == "int";
}

void ScalarConverter::changeCharToDataType(std::string str)
{
	charValue = c_str(str);
	intValue = stringToInt(str);
	floatValue = static_cast<float>(intValue);
	doubleValue = static_cast<double>(intValue);
}

void ScalarConverter::changeIntToDataType(std::string str)
{
	charValue = 
	intValue = 
}

void ScalarConverter::changeFloatToDataType(std::string str)
{}

void ScalarConverter::changeDoubleToDataType(std::string str)
{}

void ScalarConverter::convert(std::string str, std::string dataType)
{
	if (dataType == char)
		changeCharToDataType(str);
	if (dataType == int)
		changeIntToDataType();
	if (dataType == float)
		changeFloatToDataType();
	if (dataType == double)
		changeDoubleToDataType();
	intValue = static_cast<int>();
	floatValue = static_cast<float>();
	doubleValue = static_cast<double>();
}