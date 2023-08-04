#include "PhoneBook.h"

void	Contact::ContactAdd()
{
	std::cout << "firstname ?ž…? ¥?•´ì£¼ì„¸?š”" << std::endl;
	std::getline(std::cin, firstname);
	std::cout << "lastname ?ž…? ¥?•´ì£¼ì„¸?š”" << std::endl;
	std::getline(std::cin, lastname);
	std::cout << "nickname ?ž…? ¥?•´ì£¼ì„¸?š”" << std::endl;
	std::getline(std::cin, nickname);
	std::cout << "phone number ?ž…? ¥?•´ì£¼ì„¸?š”" << std::endl;
	std::getline(std::cin, phone_number);
	std::cout << "secret ?ž…? ¥?•´ì£¼ì„¸?š”" << std::endl;
	std::getline(std::cin, darkset_secret);
}

void	Contact::ContactSimpleInfoDisplay()
{
	std::cout << firstname << "|" << std::setw(10) << lastname << "|" << std::setw(10) << nickname;
}

// void	Contact::ContactDisplay()
// {
	
// }