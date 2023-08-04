#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <string>
#include <iomanip>

class Contact {

	private :
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkset_secret;

	public :
		void	ContactAdd();
		//void	ContactDisplay();
		void	ContactSimpleInfoDisplay();
};

class PhoneBook {

	private :
		Contact contact_arr[8];
		int	index;

	public :
		PhoneBook();
		void	PhoneBookAdd(Contact contact);
		void	PhoneBookShow();
};

#endif