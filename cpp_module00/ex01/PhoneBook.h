#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>

class Contact {

	private :
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkset_secret;

	public :
		void	contact_add();
		void	contact_show();
};

#endif