
#include "gildong.h"

Human::Human(const char* iname, int iage , const char* ijob)
{
	strcpy_s(name, iname);
	age = iage;
	strcpy_s(job, ijob);
}

void Human::humanInfo()
{
	std::cout << "name : " << name <<std::endl;
	std::cout << "age : " << age << std::endl;
	std::cout << "job : " << job << std::endl;
}