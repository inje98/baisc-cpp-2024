#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
//#include<cstring>
using namespace std;

class Grade
{
	char* name;
	int kr;
	int eng;
	int math;

public:

	Grade() : name(), kr(), math(), eng()
	{
		cout << "�⺻������ ȣ��" << endl;
	}

	Grade(const char* iname, int kr, int eng, int math) :kr(kr), eng(eng), math(math)
	{
		//cout << "������ ȣ��" << endl;
		int len = strlen(iname) + 1;
		name = new char[len];
		strcpy(name, iname);
	}

	~Grade()
	{
		//cout << "�Ҹ��� ȣ��" << endl;
		delete[] name;
	}

	void GetGrade(const char* iname, int kr, int eng, int math)
	{
		int len = strlen(iname) + 1;
		name = new char[len];
		strcpy(name, iname);
		this->kr = kr;
		this->eng = eng;
		this->math = math;
	}

	

	int GetKr() { return kr; }

	int Geteng() { return eng; }

	int Getmath() { return math;}

	int sum()
	{
		int sum = kr + eng + math;
		return sum;
	}

	double avr()
	{
		return sum() / 3.0;
	}
};


int main()
{
	Grade gradeAry[3];  // ��ü �迭


	for (int i = 0; i < 3; i++)
	{
		char name[20] = {};

		cout << "�̸�: ";
		cin >> name;

		int kr, math, eng;

		cout << "���� ����: ";
		cin >> kr;

		cout << "���� ����: ";
		cin >> eng;

		cout << "���� ����: ";
		cin >> math;

		gradeAry[i].GetGrade(name, kr, eng, math);
	}

	cout << "\n\n================= �л��� ���� / ���=================\n\n" << endl;


	for (int i = 0; i < 3; i++)
	{
		//cout << "����: " << gradeAry[i]->sum() << ", " << gradeAry[i]->avr() << endl;
		printf("%d��° �л� ����: %d, ����: %.1lf\n", i + 1, gradeAry[i].sum(), gradeAry[i].avr());

	}

	cout << "\n\n================= ���� ���� / ���=================\n\n" << endl;


	int kr_sum = 0;
	int eng_sum = 0;
	int math_sum = 0;

	for (int i = 0; i < 3; i++)
	{
		kr_sum += gradeAry[i].GetKr();
		eng_sum += gradeAry[i].Geteng();
		math_sum += gradeAry[i].Getmath();
	}

	cout << "���� ����: " << kr_sum << endl;
	cout << "���� ���: " << kr_sum / 3 << endl;

	cout << "\n���� ����: " << eng_sum << endl;
	cout << "���� ���: " << eng_sum / 3 << endl;

	cout << "\n���� ����: " << math_sum << endl;
	cout << "���� ���: " << math_sum / 3 << endl;

	return 0;
}