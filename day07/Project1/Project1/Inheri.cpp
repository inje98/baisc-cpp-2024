#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;


class Person
{
private:
	int age;
	char name[50];

public:
	Person(int myage, const char* myname)
	{
		cout << "何葛积己磊 角青" << endl;

		age = myage;
		strcpy(name, myname);
	}
	void whatYouName() const
	{
		cout << "My name is " << name << endl;
	}

	void howOldAreYou() const
	{
		cout << "I'm " << age << "years old" << endl;
	}
};

class UnivStudent : public Person
{
private:
	char major[50];

public:
	UnivStudent(const char* myname, int myage, const char* mymajor) : Person(myage, myname)
	{
		cout << "磊侥 积己磊 角青" << endl;
		strcpy(major, mymajor);
	}
	void WhoAreYou() const
	{
		whatYouName();
		howOldAreYou();
		cout << "My major is " << major << endl << endl;
	}
};

int main(void)
{
	UnivStudent ustd1("Lee", 22, "Computer eng.");
	ustd1.WhoAreYou();

	UnivStudent ustd2("Yoon", 21, "Electronic eng.");
	ustd2.WhoAreYou();

	return 0;
}
