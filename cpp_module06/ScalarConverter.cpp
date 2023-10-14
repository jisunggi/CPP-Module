#include "ScalarConverter.hpp"

std::string ScalarConverter::dataType;
char ScalarConverter::charValue;
int ScalarConverter::intValue;
float ScalarConverter::floatValue;
double ScalarConverter::doubleValue;
int ScalarConverter::error;

ScalarConverter::ScalarConverter()
{
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
	error = scalarConverter.error;
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
		error = scalarConverter.error;
	}
	std::cout << "ScalarConverter : Copy assignment operator called" << std::endl;
	return *this;
}

void ScalarConverter::printCharChangeValue()
{
	std::cout << "char : ";
	if (!(intValue >= 0 && intValue <= 127))
		std::cout << "impossible" << std::endl;
	else if ((charValue >= 0 && charValue <= 31) || charValue == 127)
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

void ScalarConverter::printIntChangeValue(std::string str)
{
	std::cout << "char : ";
	if (!(intValue >= 0 && intValue <= 127))
		std::cout << "impossible" << std::endl;
	else if ((charValue >= 0 && charValue <= 31) || charValue == 127)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "\'" << charValue << "\'" << std::endl;
	std::cout << "int : ";
	std::cout << intValue << std::endl;
	if (str.size() >= 6)
	{
		std::cout << "float : ";
		std::cout << floatValue << std::endl;
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

void ScalarConverter::printFloatChangeValue(std::string str)
{
	std::cout << "char : ";
	if (!(intValue >= 0 && intValue <= 127) || error)
		std::cout << "impossible" << std::endl;
	else if ((charValue >= 0 && charValue <= 31) || charValue == 127)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "\'" << charValue << "\'" << std::endl;
	
	std::cout << "int : ";
	if (error)
		std::cout << "impossible" << std::endl;
	else
		std::cout << intValue << std::endl;
	
	if (str == "-inff" || str == "+inff" || str == "nanf")
	{
		std::cout << "float : " << str << std::endl;
		str.resize(str.size() - 1);
		std::cout << "double : " << str << std::endl;
		return ;
	}
	if (intValue != floatValue)
	{
		std::cout << "float : " << floatValue << "f" << std::endl;
		std::cout << "double : " << doubleValue << std::endl;
	}
	else
	{
		std::cout << "float : " << floatValue << ".0f" << std::endl;
		std::cout << "double : " << doubleValue << ".0" << std::endl;
	}
}

void ScalarConverter::printDoubleChangeValue(std::string str)
{
	std::cout << "char : ";
	if (!(intValue >= 0 && intValue <= 127) || error)
		std::cout << "impossible" << std::endl;
	else if ((charValue >= 0 && charValue <= 31) || charValue == 127)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "\'" << charValue << "\'" << std::endl;
	std::cout << "int : ";
	if (error)
		std::cout << "impossible" << std::endl;
	else
		std::cout << intValue << std::endl;
	if (str == "-inf" || str == "+inf" || str == "nan")
	{
		std::cout << "float : " << str << "f" << std::endl;
		std::cout << "double : " << str << std::endl;
		return ;
	}
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

// void ScalarConverter::printValue(std::string str)
// {
// 	if (dataType == "char")
// 		printCharChangeValue();
// 	if (dataType == "int")
// 		printIntChangeValue(str);
// 	if (dataType == "float")
// 		printFloatChangeValue();
// 	if (dataType == "double")
// 		printDoubleChangeValue();
// }

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

void ScalarConverter::changeCharToDataType(std::string str)
{
	std::cout << str << "--------" << std::endl;
	charValue = str[0];
	intValue = static_cast<int>(charValue);
	floatValue = static_cast<float>(charValue);
	doubleValue = static_cast<double>(charValue);
	std::cout << intValue << "--------" << std::endl;
	printCharChangeValue();
}

void ScalarConverter::changeIntToDataType(std::string str)
{
	intValue = stringToInt(str);
	if (dataType == "double")
		return ;
	charValue = static_cast<char>(intValue);
	floatValue = static_cast<float>(intValue);
	doubleValue = static_cast<double>(intValue);
	std::cout << floatValue << "--------" << std::endl;
	printIntChangeValue(str);
}

void ScalarConverter::changeFloatToDataType(std::string str)
{
	//str.resize(str.size() - 1);
	std::cout << str << "--------" << std::endl;
	floatValue = stringToFloat(str);
	charValue = static_cast<char>(floatValue);
	intValue = static_cast<int>(floatValue);
	doubleValue = static_cast<double>(floatValue);
	std::cout << floatValue << "--------" << std::endl;
	printFloatChangeValue(str);
}

void ScalarConverter::changeDoubleToDataType(std::string str)
{
	std::cout << dataType << "--------" << std::endl;
	doubleValue = stringToDouble(str);
	charValue = static_cast<char>(doubleValue);
	floatValue = static_cast<float>(doubleValue);
	intValue = static_cast<int>(doubleValue);
	std::cout << doubleValue << "--------" << std::endl;
	std::cout << floatValue << "--------" << std::endl;
	printDoubleChangeValue(str);
}

std::string ScalarConverter::checkDataType(std::string str)
{
	if (str == "-inff" || str == "+inff" || str == "nanf")
	{
		error = 1;
		return dataType = "float";
	}
	if (str == "-inf" || str == "+inf" || str == "nan")
	{
		error = 1;
		return dataType = "double";
	}
	if (str.size() == 1 && !(str >= "0" && str <= "9"))
		return dataType = "char";
	
	std::string::size_type dotIdx = str.find(".");
	for (std::string::size_type i = 0; i < str.size(); i++)
	{
		if (str[0] == '-')
			continue;
		if (!(str[i] >= '0' && str[i] <= '9') && i != dotIdx && i != str.size() - 1)
			throw ScalarConverter::wrongInputException();
	}
	if (!(str[str.size() - 1] >= '0' && str[str.size() - 1] <= '9') && str[str.size() - 1] != 'f')
		throw ScalarConverter::wrongInputException();
	if (str.find(".") == std::string::npos && str.find("f", str.size() - 1) != std::string::npos)
		throw ScalarConverter::wrongInputException();
	if (str.find(".", str.size() - 2) != std::string::npos && str.find("f", str.size() - 1) != std::string::npos)
		throw ScalarConverter::wrongInputException();
	if (str.find(".") != std::string::npos && str.find("f", str.size() - 1) != std::string::npos)
		return dataType = "float";
	if (str.find(".") != std::string::npos)
		return dataType = "double";
	return dataType = "int";
}

void ScalarConverter::convert(std::string str)
{
	try
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
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

const char *ScalarConverter::wrongInputException::what() const throw()
{
	return "Wrong Input";
}