

#include <iostream>

#include "Contact.hpp"

class Phonebook{

	public:
		Phonebook();
		~Phonebook();

		void Add_Contact();
		void Search_Contact();

	private:
		Contact contact[8];
};