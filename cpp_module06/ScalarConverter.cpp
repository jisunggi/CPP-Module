#include "ScalarConverter.hpp"

std::string ScalarConverter::dataType;
char ScalarConverter::charValue;
int ScalarConverter::intValue;
float ScalarConverter::floatValue;
double ScalarConverter::doubleValue;

ScalarConverter::ScalarConverter()
{
	charValue = 0;
	intValue = 0;
	floatValue = 0;
	doubleValue = 0;
	std::cout << "ScalarConverter : Default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter : Destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &scalarConverter)
{
	dataType = scalarConverter.dataType;
	charValue = scalarConverter.charValue;
	intValue =  scalarConverter.intValue;
	floatValue = scalarConverter.floatValue;
	doubleValue = scalarConverter.doubleValue;
	std::cout << "ScalarConverter : Copy constructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &scalarConverter)
{
	if (this != &scalarConverter)
	{
		dataType = scalarConverter.dataType;
		charValue = scalarConverter.charValue;
		intValue =  scalarConverter.intValue;
		floatValue = scalarConverter.floatValue;
		doubleValue = scalarConverter.doubleValue;
	}
	std::cout << "ScalarConverter : Copy assignment operator called" << std::endl;
	return *this;
}

void ScalarConverter::printCharChangeValue()
{
	std::cout << "char : ";
	if ((charValue >= 0 && charValue <= 31) || charValue == 127)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "\'" << charValue << "\'" << std::endl;
	std::cout << "int : ";
	std::cout << intValue << std::endl;
	std::cout << "float : ";
	std::cout << floatValue << ".0f" << std::endl;
	std::cout << "double : ";
	std::cout << doubleValue << ".0" << std::endl;
}

void ScalarConverter::printIntChangeValue()
{
	std::cout << "char : ";
	std::cout << "\'" << charValue << "\'" << std::endl;
	std::cout << "int : ";
	std::cout << intValue << std::endl;
	std::cout << "float : ";
	std::cout << floatValue << ".0f" << std::endl;
	std::cout << "double : ";
	std::cout << doubleValue << ".0" << std::endl;
}

void ScalarConverter::printFloatChangeValue()
{
	std::cout << "char : ";
	if ((charValue >= 0 && charValue <= 31) || charValue == 127)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "\'" << charValue << "\'" << std::endl;
	std::cout << "int : ";
	std::cout << intValue << std::endl;
	if (intValue != floatValue)
	{
		std::cout << "float : ";
		std::cout << floatValue << "f" << std::endl;
		std::cout << "double : ";
		std::cout << doubleValue << std::endl;
	}
	else
	{
		std::cout << "float : ";
		std::cout << floatValue << ".0f" << std::endl;
		std::cout << "double : ";
		std::cout << doubleValue << ".0" << std::endl;
	}
}

void ScalarConverter::printDoubleChangeValue()
{
		std::cout << "char : ";
	if ((charValue >= 0 && charValue <= 31) || charValue == 127)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "\'" << charValue << "\'" << std::endl;
	std::cout << "int : ";
	std::cout << intValue << std::endl;
	if (intValue != floatValue)
	{
		std::cout << "float : ";
		std::cout << floatValue << "f" << std::endl;
		std::cout << "double : ";
		std::cout << doubleValue << std::endl;
	}
	else
	{
		std::cout << "float : ";
		std::cout << floatValue << ".0f" << std::endl;
		std::cout << "double : ";
		std::cout << doubleValue << ".0" << std::endl;
	}
}

void ScalarConverter::printValue()
{
	if (dataType == "char")
		printCharChangeValue();
	if (dataType == "int")
		printIntChangeValue();
	if (dataType == "float")
		printFloatChangeValue();
	if (dataType == "double")
		printDoubleChangeValue();
}

std::string ScalarConverter::checkFloatOrDouble(char *argv)
{
	for (int idx = 0; argv[idx]; idx++)
	{
		if (argv[idx] == 'f')
		{
			argv[idx] = '\0';
			return dataType = "float";
		}
	}
	return dataType = "double";
}

std::string ScalarConverter::checkDataType(std::string str)
{
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return dataType = "float";
	if (str == "-inf" || str == "+inf" || str == "nan")
		return dataType = "double";
	if (str.length() == 1 && !(str >= "0" && str <= "9"))
		return dataType = "char";
	
	std::string::size_type dotIdx = str.find(".");
	for (std::string::size_type i = 0; i < str.size(); i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9') && i != dotIdx && i != str.size() - 1)
			return dataType = "error" ;
	}
	if (str.find("f", str.length() - 1) == std::string::npos)
		return dataType = "error222" ;
	if (str.find(".") == std::string::npos && str.find("f", str.length() - 1) != std::string::npos)
		return dataType = "error333" ;
	if (str.find(".") != std::string::npos && str.find("f", str.length() - 1) != std::string::npos)
		return dataType = "float";
	if (str.find(".") != std::string::npos)
		return dataType = "double";
	return dataType = "int";
}

void ScalarConverter::changeCharToDataType(std::string str)
{
	std::cout << str << "--------" << std::endl;
	intValue = stringToInt(str);
	charValue = static_cast<int>(intValue);
	floatValue = static_cast<float>(intValue);
	doubleValue = static_cast<double>(intValue);
	std::cout << intValue << "--------" << std::endl;
}

void ScalarConverter::changeIntToDataType(std::string str)
{
	intValue = stringToInt(str);
	charValue = static_cast<int>(intValue);
	floatValue = static_cast<float>(intValue);
	doubleValue = static_cast<double>(intValue);
}

void ScalarConverter::changeFloatToDataType(std::string str)
{
	std::cout << str << "--------" << std::endl;
	floatValue = stringToFloat(str);
	charValue = static_cast<char>(floatValue);
	intValue = static_cast<int>(floatValue);
	doubleValue = static_cast<double>(floatValue);
	std::cout << floatValue << "--------" << std::endl;
}

void ScalarConverter::changeDoubleToDataType(std::string str)
{
	doubleValue = stringToDouble(str);
	charValue = static_cast<int>(doubleValue);
	floatValue = static_cast<float>(doubleValue);
	intValue = static_cast<int>(doubleValue);
}

void ScalarConverter::convert(std::string str)
{
	checkDataType(str);
	std::cout << dataType << "--------" << std::endl;
	if (dataType == "char")
		changeCharToDataType(str);
	if (dataType == "int")
		changeIntToDataType(str);
	if (dataType == "float")
		changeFloatToDataType(str);
	if (dataType == "double")
		changeDoubleToDataType(str);
	printValue();
}