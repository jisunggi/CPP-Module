#include "PhoneBook.h"

void	Contact::ContactAdd()
{
	std::cout << "firstname ?? ₯?΄μ£ΌμΈ?" << std::endl;
	std::getline(std::cin, firstname);
	std::cout << "lastname ?? ₯?΄μ£ΌμΈ?" << std::endl;
	std::getline(std::cin, lastname);
	std::cout << "nickname ?? ₯?΄μ£ΌμΈ?" << std::endl;
	std::getline(std::cin, nickname);
	std::cout << "phone number ?? ₯?΄μ£ΌμΈ?" << std::endl;
	std::getline(std::cin, phone_number);
	std::cout << "secret ?? ₯?΄μ£ΌμΈ?" << std::endl;
	std::getline(std::cin, darkset_secret);
}

void	Contact::ContactSimpleInfoDisplay()
{
	std::cout << firstname << "|" << std::setw(10) << lastname << "|" << std::setw(10) << nickname;
}

// void	Contact::ContactDisplay()
// {
	
// }