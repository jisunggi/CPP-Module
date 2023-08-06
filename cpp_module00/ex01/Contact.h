#ifndef CONTACT_H
#define CONTACT_H

#include "PhoneBook.h"
#include <iostream>

class Contact {

	private :
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkset_secret;
		std::string	SubstrField(std::string);

	public :
		void	Insert();
		void	Display();
		void	DisplaySimpleField();
		// std::string getField();
};

#endif