#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;
//5���� �̸���, ������ 3���� ������ �Է¹޾� �л��� ������ ���, �׸��� ���� ������ ����� ���Ͻÿ�
class Grade
{
	char* name;  // �����Ҵ�
	int kr;
	int math;
	int english;

public:
	Grade() : name(nullptr), kr(0), math(0), english(0) 
	{
		cout << "�⺻������" << endl;
	}

	Grade(const char* iname, int kr, int math, int english): kr(kr), math(math), english(english)
	{
		cout << "������" << endl;

		int len = strlen(iname)+1;
		name = new char[len];
		strcpy(name, iname);

	}
	Grade(const Grade& copy) : kr(copy.kr), math(copy.math), english(copy.english)
	{
		cout << "���� ����" << endl;
		int len = strlen(copy.name) + 1;
		name = new char[len];
		strcpy(name, copy.name);
	}

	~Grade()
	{
		cout << "�Ҹ���" << endl;
		delete[] name;

	}


};

int main()
{
	Grade student[5];


	for(int i = 0; i < 2; i++)
	{
		char name[50];

		cout << "�л� �̸�: ";
		cin >> name;


		int kr, math, english;

		cout << "���� ����: ";
		cin >> kr;

		cout << "���� ����: ";
		cin >> math;

		cout << "���� ����: ";
		cin >> english;

		student[i] = Grade(name, kr, math, english);
	}


	

	return 0;
}