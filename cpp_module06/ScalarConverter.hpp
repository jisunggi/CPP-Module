#ifndef SCALARCONVERTER_CPP
# define SCALARCONVERTER_CPP

#include <iostream>
#include <string>
#include <sstream>

class ScalarConverter
{
	private :
		std::string dataType;
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
		void convert(std::string str);
		void printValue();

		void changeCharToDataType(std::string str);
		void changeIntToDataType(std::string str);
		void changeFloatToDataType(std::string str);
		void changeDoubleToDataType(std::string str);

};

int	stringToInt(std::string string);
float stringToFloat(std::string string);
//std::string floatToString(int integer);

#endif