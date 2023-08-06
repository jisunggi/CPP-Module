#include "PhoneBook.h"

int main (void)
{
	PhoneBook phonebook;
	std::string cmd = "start!";

	while (cmd != "exit" && !std::cin.eof())
	{
		std::cout << "add, search, exit 중 입력해주세요" << std::endl;
		std::getline(std::cin, cmd);
		if (cmd == "add")
		{
			Contact contact;
			contact.Insert();
			phonebook.Add(contact);
		}
		else if (cmd == "search")
			phonebook.ShowList();
		std::cout << std::endl;
	}
	return 0;
}