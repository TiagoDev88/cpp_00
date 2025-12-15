
#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

std::string Contact::get_firstname(void) const
{
	return this->_first_name;
}

std::string Contact::get_lastname(void) const
{
	return this->_last_name;
}

std::string Contact::get_nickname(void) const
{
	return this->_nickname;
}

std::string Contact::get_phonenumber(void) const
{
	return this->_phone_number;
}

std::string Contact::get_darkestsecret(void) const
{
	return this->_darkest_secret;
}

void Contact::set_firstname(std::string firstname){
	this->_first_name = firstname;
}


void Contact::set_lastname(std::string lastname){
	this->_last_name = lastname;
}

void Contact::set_nickname(std::string nickname){
	this->_nickname = nickname;
}

void Contact::set_darkest_secret(std::string darkest_secret){
	this->_darkest_secret = darkest_secret;
}

void Contact::set_phonenumber(std::string phone){
	this->_phone_number = phone;
}

std::string Contact::get_input(std::string s, int flag)
{
	std::string line;

	while (std::getline(std::cin, line))
	{
		if (line.empty() || is_only_space(line))
		{
			std::cout << "Empty input is not allowed!\n" << s;
			line.clear();
			continue;
		}
		else if (flag == 1 && !is_alpha(line))
		{
			std::cout << "Insert valid name! Only letters\n" << s;
			line.clear();
			continue;
		}
		else if (flag == 2 && !is_number(line))
		{
			std::cout << "Insert valid phone number!\n" << s;
			line.clear();
			continue;
		}
		break;
	}
	line = clear_line(line);
	return line;
}
void Contact::set_newcontact(Contact *contact){

	std::string line;

	std::cout << "Insert First Name: ";
	line = get_input("Insert First Name: ", 1);
	contact->set_firstname(line);

	std::cout << "Insert Last Name: ";
	line = get_input("Insert Last Name: ", 1);
	contact->set_lastname(line);

	std::cout << "Insert Nickname: ";
	line = get_input("Insert Nickname: ", 0);
	contact->set_nickname(line);

	std::cout << "Insert Phone Number: ";
	line = get_input("Insert Phone Number: ", 2);
	contact->set_phonenumber(line);

	std::cout << "Insert Darkest Secret: ";
	line = get_input("Insert Darkest Secret: ", 0);
	contact->set_darkest_secret(line);
}
