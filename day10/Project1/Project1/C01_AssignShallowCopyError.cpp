#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
using namespace std;

class Person
{
private:
	char* name;
	int age;

public:
	Person(const char* myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}

	Person& operator=(const Person& copy)
	{
		delete[] name;
		int len = strlen(copy.name) + 1;
		name = new char[len];
		strcpy(name, copy.name);
		age = copy.age;
		return *this;
	}
	Person(const Person& copy)
	{
		// delete[] name;
		int len = strlen(copy.name) + 1;
		name = new char[len];
		strcpy(name, copy.name);
		age = copy.age;
	}


	void ShowPersonInfo() const
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~Person()
	{
		delete[] name;
		cout << "called destructor!" << endl;
	}
};

int main(void)
{
	Person man1("Lee dong woo", 29);
	Person man2("Yoon ji yul", 22);
	man2 = man1;  // 얘는 operator=로 가는거임

	Person man3 = man1;  // 객체를 '생성' 해야 복사 생성자로 가는거임

	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	man3.ShowPersonInfo();

	return 0;
}