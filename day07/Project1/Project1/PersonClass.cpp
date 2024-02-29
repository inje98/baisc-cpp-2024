#define _CRT_SECURE_NO_WARNINGS
#include<iostream>


// #pragma warning(disable:4996)
using namespace std;

class Person
{
private:
	char* name;
	int age;

public:
	Person(const char* iname, int iage) :age(iage)
	{
		int len = strlen(iname) + 1;
		name = new char[len];
		strcpy(name, iname);
		cout << "��������� ȣ��" << endl;
	}

	Person(const Person& copy) : age(copy.age)
	{
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
		cout << "������ ȣ��" << endl;

	}
	~Person()
	{
		delete[] name;
		cout << "�Ҹ��� ȣ��" << endl;
	}

	void PersonInfo()
	{
		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
	}
};


int main(void)
{
	Person P1("ȫ�浿", 50);
	Person P2 = P1;

	P1.PersonInfo();
	P2.PersonInfo();

	return 0;
}