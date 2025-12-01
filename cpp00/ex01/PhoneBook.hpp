#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP


#include "Contact.hpp"

class Phonebook{

	public:
		Phonebook();
		~Phonebook();

		void Add_Contact(void);
		void Search_Contact(void);
		void Print_contact(void);

	private:
		Contact _contact[8];
		int _count_contacts;
};

#endif