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
	Student(int iID, const char* iname, const char* imajor, int iage)   // 생성자
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
		cout << "학번: " << ID << endl;
		cout << "이름: " << name << endl;
		cout << "전공: " << major << endl;
		cout << "나이: " << age << endl;
	}
};

int main(void)
{
	Student s1(20174266, "김인제", "전자공학", 27);
	s1.studentInfo();
}