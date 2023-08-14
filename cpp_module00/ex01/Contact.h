#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact {

	private :
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkset_secret;
		std::string	SubstrField(std::string);

	public :
		int     Insert();
		void	Display();
		void	DisplaySimpleField();
};

#endif