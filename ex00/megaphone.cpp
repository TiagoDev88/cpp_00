

#include <iostream>

int main(int argc, char **argv){
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	} else {
		for (int i = 1; i < argc; i++) {
			std::string arg = argv[i];
			for (int j = 0; arg[j]; j++) {
				std::cout << static_cast<char>(std::toupper(arg[j]));
			}
		}
	}
	std::cout << '\n';
	return 0;
}
