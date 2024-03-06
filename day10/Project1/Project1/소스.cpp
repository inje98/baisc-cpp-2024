#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;
//5명의 이름과, 국영수 3과목 점수를 입력받아 학생별 총점과 평균, 그리고 과목별 총점과 평균을 구하시오
class Grade
{
	char* name;  // 동적할당
	int kr;
	int math;
	int english;

public:
	Grade() : name(nullptr), kr(0), math(0), english(0) 
	{
		cout << "기본생성자" << endl;
	}

	Grade(const char* iname, int kr, int math, int english): kr(kr), math(math), english(english)
	{
		cout << "생성자" << endl;

		int len = strlen(iname)+1;
		name = new char[len];
		strcpy(name, iname);

	}
	Grade(const Grade& copy) : kr(copy.kr), math(copy.math), english(copy.english)
	{
		cout << "복사 생성" << endl;
		int len = strlen(copy.name) + 1;
		name = new char[len];
		strcpy(name, copy.name);
	}

	~Grade()
	{
		cout << "소멸자" << endl;
		delete[] name;

	}


};

int main()
{
	Grade student[5];


	for(int i = 0; i < 2; i++)
	{
		char name[50];

		cout << "학생 이름: ";
		cin >> name;


		int kr, math, english;

		cout << "국어 점수: ";
		cin >> kr;

		cout << "수학 점수: ";
		cin >> math;

		cout << "영어 점수: ";
		cin >> english;

		student[i] = Grade(name, kr, math, english);
	}


	

	return 0;
}