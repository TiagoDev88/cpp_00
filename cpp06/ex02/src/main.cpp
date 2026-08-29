#include "Base.hpp"

int main(void)
{
    std::srand(std::time(NULL));

	Base* inst = generate();
	Base& instRef = *inst;
	Base* nul = NULL;

	identify(inst);
	identify(*inst);
	identify(instRef);
	identify(nul);

	delete inst;
	return 0;
}
