
#include "PhoneBook.hpp"

Phonebook::Phonebook()
{
	this->_count_contacts = 0;
}

Phonebook::~Phonebook(){}

void Phonebook::Add_Contact(void){

	int index = _count_contacts % 8;
	if (_count_contacts == 8){
		std::cout << "Warning: Phonebook is full!" << std::endl;
		std::cout << "New contact replace the oldest contact of list" << std::endl;
	}
	_contact[index].set_newcontact(&_contact[index]);
	this->_count_contacts++;
	std::cout << "\n----- Contact added at index " << index << "! -----" << std::endl;
}

void Phonebook::Search_Contact(void){

	if (this->_count_contacts == 0)
	{
		std::cout << "\n|-------------------------------------------|" << std::endl;
		std::cout << "|----Phonebook is empty! Add one contact!---|" << std::endl;
		std::cout << "|-------------------------------------------|" << std::endl;
		return;
	}

	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < this->_count_contacts && i < 8; i++){
		std::cout << "|" << std::setw(10) << i << "|";
		std::string first_name = _contact[i].get_firstname();

		if (first_name.length() > 10)
			first_name = first_name.substr(0, 9) + ".";

		std::cout << std::setw(10) << first_name << "|";
		std::string last_name = _contact[i].get_lastname();

		if (last_name.length() > 10)
			last_name = last_name.substr(0, 9) + ".";

		std::cout << std::setw(10) << last_name << "|";
		std::string nickname = _contact[i].get_nickname();

		if (nickname.length() > 10)
			nickname = nickname.substr(0, 9) + ".";
			
		std::cout << std::setw(10) << nickname << "|" << std::endl;
	}
	Print_contact();
}

void Phonebook::Print_contact(void)
{
	std::string s = "Please choose a index for more details: ";
	std::string line;
	int index = -1;

	std::cout << "\n\n" << s;

	while (std::getline(std::cin, line))
	{
		if (line.empty() || is_only_space(line))
		{
			std::cout << "Empty input is not allowed!\n" << s;
			line.clear();
			continue;
		}
		else if (is_number(line))
		{
			index = std::atoi(line.c_str());
			if (index < 0 || index >= this->_count_contacts || index >= 8)
			{
				std::cout << "Index out of range! Try again.\n" << s;
				continue;
			}
			break;
		}
		else
			std::cout << "Please choose a number from the index.\n" << s;
	}
	std::cout << "\n---------------------------------------------\n";
	std::cout << "First Name: " << _contact[index].get_firstname() << std::endl;
	std::cout << "Last Name: " << _contact[index].get_lastname() << std::endl;
	std::cout << "Nickname: " << _contact[index].get_nickname() << std::endl;
	std::cout << "Phone Number: " << _contact[index].get_phonenumber() << std::endl;
	std::cout << "Darkest Secret: " << _contact[index].get_darkestsecret() << std::endl;
	std::cout << "---------------------------------------------\n";
	return;
}
