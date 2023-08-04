#include "PhoneBook.h"

PhoneBook::PhoneBook()
{
	index = 0;
}

void	PhoneBook::PhoneBookAdd(Contact contact)
{
	std::cout << index << std::endl;
	if (index != 8)
	{
		contact_arr[index] = contact;
		index++;
		std::cout << index << std::endl;
		return ;
	}
	index = 0;
	contact_arr[index] = contact;
	index++;
}

void	PhoneBook::PhoneBookShow()
{
	std::cout << index << std::endl;
	std::cout << "aaa" << std::endl;
	for (int i = 0; i < index; i++)
	{
		std::cout << "bbb" << std::endl;
		std::cout << i + 1 << "|";
		contact_arr[index].ContactSimpleInfoDisplay();
	}
}