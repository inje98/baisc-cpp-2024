#include<iostream>


using namespace std;


class Student
{
private:
	int ID;
	char* name;
	string major;
	int age;

public:
	Student(int iID, const char* iname, const char* imajor, int iage)   // ������
	{
		ID = iID;
		name = new char[strlen(iname) + 1];
		strcpy_s(name, strlen(iname) + 1, iname);
		major = imajor;
		age = iage;
	}
	~Student()
	{
		delete[] name;
	}

	void studentInfo() const
	{
		cout << "�й�: " << ID << endl;
		cout << "�̸�: " << name << endl;
		cout << "����: " << major << endl;
		cout << "����: " << age << endl;
	}
};

int main(void)
{
	Student s1(20174266, "������", "���ڰ���", 27);
	s1.studentInfo();
}