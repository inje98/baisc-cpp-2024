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
		cout << "기본생성자 호출" << endl;
	}

	Grade(const char* iname, int kr, int eng, int math) :kr(kr), eng(eng), math(math)
	{
		//cout << "생성자 호출" << endl;
		int len = strlen(iname) + 1;
		name = new char[len];
		strcpy(name, iname);
	}

	~Grade()
	{
		//cout << "소멸자 호출" << endl;
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
	Grade gradeAry[3];  // 객체 배열


	for (int i = 0; i < 3; i++)
	{
		char name[20] = {};

		cout << "이름: ";
		cin >> name;

		int kr, math, eng;

		cout << "국어 점수: ";
		cin >> kr;

		cout << "영어 점수: ";
		cin >> eng;

		cout << "수학 점수: ";
		cin >> math;

		gradeAry[i].GetGrade(name, kr, eng, math);
	}

	cout << "\n\n================= 학생별 총점 / 평균=================\n\n" << endl;


	for (int i = 0; i < 3; i++)
	{
		//cout << "총점: " << gradeAry[i]->sum() << ", " << gradeAry[i]->avr() << endl;
		printf("%d번째 학생 총점: %d, 평점: %.1lf\n", i + 1, gradeAry[i].sum(), gradeAry[i].avr());

	}

	cout << "\n\n================= 과목별 총점 / 평균=================\n\n" << endl;


	int kr_sum = 0;
	int eng_sum = 0;
	int math_sum = 0;

	for (int i = 0; i < 3; i++)
	{
		kr_sum += gradeAry[i].GetKr();
		eng_sum += gradeAry[i].Geteng();
		math_sum += gradeAry[i].Getmath();
	}

	cout << "국어 총점: " << kr_sum << endl;
	cout << "국어 평균: " << kr_sum / 3 << endl;

	cout << "\n영어 총점: " << eng_sum << endl;
	cout << "영어 평균: " << eng_sum / 3 << endl;

	cout << "\n수학 총점: " << math_sum << endl;
	cout << "수학 평균: " << math_sum / 3 << endl;

	return 0;
}