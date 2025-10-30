
#include "PhoneBook.hpp"

int main(void){

	Phonebook Phone;

	std::string line;

	std::cout << "Welcome to Phonebook" << std::endl;
	while (1)
	{
		std::cout << "What do you want to do?" << std::endl;
		std::cout << "SEARCH" << std::endl;
		std::cout << "ADD" << std::endl;
		std::cout << "EXIT" << std::endl;
		std::cin >> line;

		std::cout << line << std::endl;
		if (line == "SEARCH")
			break; // vou colocar aqui a funcao para procurar os contactos
		else if (line == "ADD")
			break; // vou colocar aqui a funcao para o ADD contact
		else if (line == "EXIT")
			return 0;
		else
			std::cout << "Invalid option!" << std::endl;
		// break;
	}
	return 0;
}