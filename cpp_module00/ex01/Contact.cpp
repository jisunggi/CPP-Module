#include "PhoneBook.h"

void	Contact::ContactAdd()
{
	std::cout << "firstname 입력해주세요" << std::endl;
	std::getline(std::cin, first_name);
	std::cout << "lastname 입력해주세요" << std::endl;
	std::getline(std::cin, last_name);
	std::cout << "nickname 입력해주세요" << std::endl;
	std::getline(std::cin, nickname);
	std::cout << "phone number 입력해주세요" << std::endl;
	std::getline(std::cin, phone_number);
	std::cout << "secret 입력해주세요" << std::endl;
	std::getline(std::cin, darkset_secret);
}

void	Contact::ContactSimpleInfoDisplay()
{
	std::cout << firstname << ""
}

void	Contact::ContactDisplay()
{
	
}