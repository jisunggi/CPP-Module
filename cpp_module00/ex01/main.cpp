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
			Contact contact;
			contact.ContactAdd();
			phonebook.PhoneBookAdd(contact);
		}
		if (cmd == "search")
		{
			phonebook.PhoneBookShow();
		}
		if (cmd == "exit")
			return;
	}
}