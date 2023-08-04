#include "PhoneBook.h"

int main (void)
{
	PhoneBook phonebook;

	while (1)
	{
		std::string cmd;

		std::getline(std::cin, cmd);
		if (cmd == "add")
		{
			std::cout << "once one time field" << std::endl;
			Contact contact;
			contact.ContactAdd();
			phonebook.PhoneBookAdd(contact);
		}
		if (cmd == "search")
		{
			std::cout << "show" << std::endl;
			phonebook.PhoneBookShow();
		}
		// if (cmd == "exit") 
	}
}