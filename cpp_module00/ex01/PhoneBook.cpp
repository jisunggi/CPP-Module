#include "PhoneBook.h"

PhoneBook::PhoneBook()
{
	index = 0;
}

void	PhoneBook::Add(Contact contact)
{
	contact_arr[index % 8] = contact;
	index++;
}

void	PhoneBook::ShowList()
{
	int size = index > 8 ? 8 : index;

	std::cout << std::string(45, '-') << std::endl;
	std::cout << "|" << std::setw(10) << "Index" << "|" 
		<< std::setw(10) << "First name" << "|" 
		<< std::setw(10) << "Last name" << "|"
		<< std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << std::string(45, '-') << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << "|" << std::setw(10) << i + 1 << "|";
		contact_arr[i].DisplaySimpleField();
		std::cout << "|" << std::endl;
	}
	if (index)
		ShowIndex();
}

int	PhoneBook::StringToInt(std::string string)
{
	std::stringstream stream;
	int integer;

	stream << string;
	stream >> integer;
	return integer;
}

void	PhoneBook::ShowIndex()
{
	std::string search_index;
	int search_index_num;

	std::cout << "인덱스를 입력해주세요" << std::endl;
	std::getline(std::cin, search_index);
	search_index_num = StringToInt(search_index);
	while (!std::cin.eof() && !(search_index_num > 0 && search_index_num <= index))
	{
		std::cout << "인덱스를 다시 입력해주세요" << std::endl;
		std::getline(std::cin, search_index);
		search_index_num = StringToInt(search_index);
	}
	if (std::cin.eof())
		return ;
	contact_arr[search_index_num - 1].Display();
}