#include "phonebook.h"

void	Contact::contact_add()
{
	std::cout << "firstname �Է����ּ���" << std::endl;
	std::cin >> first_name;
	std::cout << "lastname �Է����ּ���" << std::endl;
	std::cin >> last_name;
	std::cout << "nickname �Է����ּ���" << std::endl;
	std::cin >> nickname;
	std::cout << "phone number �Է����ּ���" << std::endl;
	std::cin >> phone_number;
	std::cout << "secret �Է����ּ���" << std::endl;
	std::cin >> darkset_secret;
}

void	Contact::contact_show()
{
	std::cout << first_name << last_name << nickname << phone_number << darkset_secret << std::endl;
}