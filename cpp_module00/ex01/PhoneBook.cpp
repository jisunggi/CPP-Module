#include "PhoneBook.h"

class PhoneBook {

	private :
		Contact contact_arr[8];
		int	idx;

	public :
		PhoneBook();
		void	PhoneBookAdd(Contact contact);
		void	PhoneBookShow();
		void	phonebook_();

};

PhoneBook::PhoneBook()
{
	idx = 0;
}

void	PhoneBook::PhoneBookAdd(Contact contact)
{
	if (idx != 8)
	{
		contact_arr[idx] = contact;
		idx++;
		return ;
	}
	idx = 0;
	contact_arr[idx] = contact;
	idx++;
}

void	PhoneBook::PhoneBookShow()
{
	
	std::cout << index
}