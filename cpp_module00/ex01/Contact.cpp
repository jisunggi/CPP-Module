#include "PhoneBook.h"

void	Contact::Insert()
{
	std::cout << "한번에 한 field를 입력해주세요" << std::endl;
	std::cout << "first_name 입력해주세요" << std::endl;
	std::getline(std::cin, first_name);
	std::cout << "last_name 입력해주세요" << std::endl;
	std::getline(std::cin, last_name);
	std::cout << "nickname 입력해주세요" << std::endl;
	std::getline(std::cin, nickname);
	std::cout << "phone number 입력해주세요" << std::endl;
	std::getline(std::cin, phone_number);
	std::cout << "secret 입력해주세요" << std::endl;
	std::getline(std::cin, darkset_secret);

	// if (isspace(first_name) || isspace(last_name) || isspace(nickname) 
	// 		|| isspace(phone_number) || isspace(darkset_secret))

}

std::string	Contact::SubstrField(std::string field)
{
	if (field.length() > 10)
		return field.substr(0, 9) + ".";
	return field;
}

void	Contact::DisplaySimpleField()
{
	std::cout << std::setw(10) << SubstrField(first_name) << "|" 
			<< std::setw(10) << SubstrField(last_name) << "|" 
			<< std::setw(10) << SubstrField(nickname);
}

void	Contact::Display()
{ 
	std::cout << "first name : ";
	std::cout << first_name <<  std::endl;
	std::cout << "last name : ";
	std::cout << last_name << std::endl;
	std::cout << "nickname : ";
	std::cout << nickname << std::endl;
	std::cout << "phone number : ";
	std::cout << phone_number << std::endl;
	std::cout << "darkset secret : ";
	std::cout << darkset_secret << std::endl;
}