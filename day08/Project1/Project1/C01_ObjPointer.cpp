#include<iostream>

using namespace std;

class Person
{
public:
	void Sleep()
	{
		cout << "Sleep" << endl;
	}
};

class Student : public Person
{
public:
	void Sleep()
	{
		cout << "Student Sleep" << endl;
	}
	void Study()
	{
		cout << "Study" << endl;
	}
};

class PartTimeStudent : public Student
{
public:
	void Work()
	{
		cout << "Work" << endl;
	}
};

int main()
{
	Person* ptr1 = new Student();
	Person* ptr2 = new PartTimeStudent();
	Student* ptr3 = new PartTimeStudent();

	// �θ�Ÿ���� ��ü �����ͷ� �ڽ� ��ü�� ����ų �� �ִ�
	// ������ �ڽ� ��ü �����ͷ� �θ� ��ü�� ����ų �� ����
	// �׸��� ������ ��ü �������� Ÿ���� ������

	ptr1->Sleep();
	ptr2->Sleep();
	ptr3->Study();
	ptr3->Sleep();

	delete ptr1;
	delete ptr2;
	delete ptr3;

	return 0;

}

