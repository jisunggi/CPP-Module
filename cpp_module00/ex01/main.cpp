#include "PhoneBook.h"

int main (void)
{
	while (1)
	{
		std::string cmd;
		PhoneBook phonebook;

		std::getline(std::cin, cmd);
		if (cmd == "add")
		{
			std::cout << "once one time field" << std::endl;
			Contact contact;
			contact.ContactAdd();
			phonebook.PhoneBookAdd(contact);
		}
		return (0);
		if (cmd == "search")
		{
			phonebook.PhoneBookShow();
		}
		// if (cmd == "exit") 
	}
}