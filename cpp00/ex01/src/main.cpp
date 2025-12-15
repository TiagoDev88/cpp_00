
#include "PhoneBook.hpp"

int main(void){

	Phonebook Phone;

	std::string line;

	std::cout << "|-----------------------------------------------|\n";
	std::cout << "|-------------Welcome to Phonebook--------------|\n";
	std::cout << "|-----------------------------------------------|\n";
	while (true)
	{
		std::cout << "\nPlease enter a command: ";
		std::cout << "(ADD, SEARCH, EXIT)" << std::endl;
		std::cout << "--> ";
		if (!std::getline(std::cin, line))
			break;
		if (line == "SEARCH")
			Phone.Search_Contact();
		else if (line == "ADD")
			Phone.Add_Contact();
		else if (line == "EXIT")
			break;
		else
			std::cout << "Invalid option!" << std::endl;
	}
	std::cout << "\n|-----------------------------------------------|";
	std::cout << "\n|-----------------See you soon !----------------|";
	std::cout << "\n|-----------------------------------------------|\n";
	return 0;
}