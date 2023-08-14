#include "PhoneBook.h"

int	checkEmpty(std::string string)
{
	int	idx = 0;
	
	if (string.length() == 0 || isspace(string[idx]))
		return 1;
	return 0;
}

int	stringToInt(std::string string)
{
	std::stringstream stream;
	int integer;

	stream << string;
	stream >> integer;
	return integer;
}

void	checkCommand(std::string cmd, PhoneBook *phonebook)
{
	if (cmd == "add")
	{
		Contact contact;
		if (!(contact.Insert()))
			phonebook->Add(contact);
	}
	else if (cmd == "search")
		phonebook->ShowList();
}

int main (void)
{
	PhoneBook phonebook;
	std::string cmd = "start!";

	while (cmd != "exit" && !std::cin.eof())
	{
		std::cout << "add, search, exit 중 입력해주세요" << std::endl;
		std::getline(std::cin, cmd);
		checkCommand(cmd, &phonebook);
		std::cout << std::endl;
	}
	return 0;
}