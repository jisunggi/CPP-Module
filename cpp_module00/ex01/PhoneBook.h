#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <cctype>

int	stringToInt(std::string string);
int	checkEmpty(std::string string);

class PhoneBook {

	private :
		Contact contact_arr[8];
		int	index;
		void	ShowIndex();

	public :
		PhoneBook();
		void	Add(Contact);
		void	ShowList();
};

#endif