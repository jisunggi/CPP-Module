#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <string>
#include <iomanip>

class Contact {

	private :
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkset_secret;

	public :
		void	ContactAdd();
		void	ContactDisplay();
		void	ContactSimpleInfoDisplay();
};

class PhoneBook {

	private :
		Contact contact[8];

	public :
		void	PhoneBookAdd(Contact contact);
		void	PhoneBookShow();
		void	phonebook_();


};

#endif