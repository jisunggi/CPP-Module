#include "PhoneBook.h"

int main (void)
{
	while (1)
	{
		std::string cmd;

		std::cin >> cmd;
		if (cmd == "add")
		{
			std::cout << "once one time field" << std::endl;
			Contact contact;
			contact.contact_add();
			contact.contact_show();
		}
		return (0);
		// if (cmd == "search")
		// {

		// }
		// if (cmd == "exit") 
	}
}