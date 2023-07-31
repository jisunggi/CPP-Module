#include "phonebook.h"

void	Contact::contact_add()
{
	std::cout << "firstname 입려해주세요" << std::endl;
	std::cin >> first_name;
	std::cout << "lastname 입려해주세요" << std::endl;
	std::cin >> last_name;
	std::cout << "nickname 입려해주세요" << std::endl;
	std::cin >> nickname;
	std::cout << "phone number 입려해주세요" << std::endl;
	std::cin >> phone_number;
	std::cout << "secret 입려해주세요" << std::endl;
	std::cin >> darkset_secret;
}

void	Contact::contact_show()
{
	std::cout << first_name << last_name << nickname << phone_number << darkset_secret << std::endl;
}