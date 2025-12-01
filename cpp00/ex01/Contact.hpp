#ifndef CONTACT_H
# define CONTACT_H


#include "Utils.hpp"
class Contact {

	public:
		Contact();
		~Contact();
		std::string get_firstname(void) const;
		std::string get_lastname(void) const;
		std::string get_nickname(void) const;
		std::string get_phonenumber(void) const;
		std::string get_darkestsecret(void) const;
		std::string get_input(std::string s, int flag);
		void set_firstname(std::string firstname);
		void set_lastname(std::string lastname);
		void set_nickname(std::string nickname);
		void set_phonenumber(std::string phonenumber);
		void set_darkest_secret(std::string darkest_secret);
		void set_newcontact(Contact *contact);

	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;
};

#endif