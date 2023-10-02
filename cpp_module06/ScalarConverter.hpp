#ifndef SCALARCONVERTER_CPP
# define SCALARCONVERTER_CPP

#include <iostream>
#include <string>
#include <sstream>

class ScalarConverter
{
	private :
		char charValue;
		int intValue;
		float floatValue;
		double doubleValue;

	public :
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter &scalarConverter);
	ScalarConverter &operator=(const ScalarConverter &scalarConverter);

	std::string checkDataType(char *argv);
	std::string checkFloatOrDouble(char *argv);
	void convert(std::string str, std::string dataType);

	void changeCharToDataType(std::string str);
	void changeIntToDataType(std::string str);
	void changeFloatToDataType(std::string str);
	void changeDoubleToDataType(std::string str);

};

#endif