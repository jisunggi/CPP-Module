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
		static int error;
		ScalarConverter();

	public :
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &scalarConverter);
		ScalarConverter &operator=(const ScalarConverter &scalarConverter);

		static std::string checkDataType(std::string str);
		static void convert(std::string str);
		//static void printValue(std::string str);

		static void changeCharToDataType(std::string str);
		static void changeIntToDataType(std::string str);
		static void changeFloatToDataType(std::string str);
		static void changeDoubleToDataType(std::string str);

		static int	stringToInt(std::string string);
		static float stringToFloat(std::string string);
		static double stringToDouble(std::string string);

		static void printCharChangeValue();
		static void printIntChangeValue(std::string str);
		static void printFloatChangeValue(std::string str);
		static void printDoubleChangeValue(std::string str);

		class wrongInputException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};

#endif