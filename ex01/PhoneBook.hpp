

#include <iostream>

#include "Contact.hpp"

class Phonebook{

	public:
		Phonebook();
		~Phonebook();

	private:
		Contact contact[8];
};