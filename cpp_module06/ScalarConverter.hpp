#ifndef SCALARCONVERTER_CPP
# define SCALARCONVERTER_CPP

#include <iostream>
#include <string>
#include <sstream>

class ScalarConverter
{
	private :
		static std::string dataType;
		static char charValue;
		static int intValue;
		static float floatValue;
		static double doubleValue;
		ScalarConverter();

	public :
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &scalarConverter);
		ScalarConverter &operator=(const ScalarConverter &scalarConverter);

		static std::string checkDataType(std::string str);
		static void convert(std::string str);
		static void printValue();

		static void changeCharToDataType(std::string str);
		static void changeIntToDataType(std::string str);
		static void changeFloatToDataType(std::string str);
		static void changeDoubleToDataType(std::string str);

		static void printCharChangeValue();
		static void printIntChangeValue();
		static void printFloatChangeValue();
		static void printDoubleChangeValue();

};

int	stringToInt(std::string string);
float stringToFloat(std::string string);
double stringToDouble(std::string string);

#endif