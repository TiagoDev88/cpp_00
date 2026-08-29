#include "Serializer.hpp"

// reinterpret_cast just reads the same bits that were already in memory and
// puts them into the new type, without changing anything.
int main(void)
{
	Data student;
	student.name = "tfilipe-";
	student.age = 37;

    std::cout << "student->name:      " << student.name << std::endl;
	std::cout << "student->value:     " << student.age << std::endl;

	uintptr_t raw = Serializer::serialize(&student);
	Data* recovered = Serializer::deserialize(raw);

	std::cout << "\nstudent address:    " << &student << std::endl;
	std::cout << "serialized raw:     " << raw << std::endl;
	std::cout << "recovered address:  " << recovered << std::endl;

	if (recovered == &student)
		std::cout << "\nOK: pointers equal" << std::endl;
	else
		std::cout << "KO: pointers its diff" << std::endl;

	std::cout << "\nrecovered->name:    " << recovered->name << std::endl;
	std::cout << "recovered->age:     " << recovered->age << std::endl;

	return (0);
}
