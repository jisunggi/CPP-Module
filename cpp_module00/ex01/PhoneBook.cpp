#include "PhoneBook.h"

PhoneBook::PhoneBook()
{
	index = 0;
}

void	PhoneBook::PhoneBookAdd(Contact contact)
{
	if (index != 8)
	{
		contact_arr[index] = contact;
		index++;
		return ;
	}
	index = 0;
	contact_arr[index] = contact;
	index++;
}

void	PhoneBook::PhoneBookShow()
{
	for (int i = 0; i < index; i++)
	{
		std::cout << i + 1 << "|";
		contact_arr[i].ContactSimpleInfoDisplay();
		std::cout << std::endl;
	}
	PhoneBookIndexShow();
}

void	PhoneBook::PhoneBookIndexShow()
{
	std::string search_index;
	std::getline(std::cin, search_index);
	std::stringstream stream;
	int search_index_num;
	stream << search_index;
	stream >> search_index_num;
	while (!(search_index_num > 0 && search_index_num <= index))
	{
		std::cout << "인덱스 범위를 다시 입력해주세요" << std::endl;
		std::getline(std::cin, search_index);
		stream << search_index;
		stream >> search_index_num;
	}
	contact_arr[search_index_num - 1].ContactDisplay();
}