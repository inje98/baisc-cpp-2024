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
	Grade(const char* iname, int kr, int eng, int math) :kr(kr), eng(eng), math(math)
	{
		int len = strlen(iname) + 1;
		name = new char[len];
		strcpy(name, iname);
	}
	~Grade()
	{
		//cout << "¼Ò¸êÀÚ È£Ãâ" << endl;
		delete[] name;
	}
	
	int GetKr()
	{
		return kr;
	}

	int Geteng()
	{
		return eng;
	}

	int Getmath()
	{
		return math;
	}

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
	Grade* gradeAry[3];  // °´Ã¼ Æ÷ÀÎÅÍ ¹è¿­


	for (int i = 0; i < 3; i++)
	{
		char name[20] = {};

		cout << "ÀÌ¸§: ";
		cin >> name;

		int kr, math, eng;

		cout << "±¹¾î Á¡¼ö: ";
		cin >> kr;

		cout << "¿µ¾î Á¡¼ö: ";
		cin >> eng;

		cout << "¼öÇÐ Á¡¼ö: ";
		cin >> math;

		gradeAry[i] = new Grade(name, kr, eng, math);
	}

	cout << "\n\n================= ÇÐ»ýº° ÃÑÁ¡ / Æò±Õ=================\n\n" << endl;


	for (int i = 0; i < 3; i++)
	{
		//cout << "ÃÑÁ¡: " << gradeAry[i]->sum() << ", " << gradeAry[i]->avr() << endl;
		printf("%d¹øÂ° ÇÐ»ý ÃÑÁ¡: %d, ÆòÁ¡: %.1lf\n",i+1, gradeAry[i]->sum(), gradeAry[i]->avr());
	
	}

	cout << "\n\n================= °ú¸ñº° ÃÑÁ¡ / Æò±Õ=================\n\n" << endl;


	int kr_sum = 0;
	int eng_sum = 0;
	int math_sum = 0;

	for (int i = 0; i < 3; i++)
	{
		kr_sum += gradeAry[i]->GetKr();
		eng_sum += gradeAry[i]->Geteng();
		math_sum += gradeAry[i]->Getmath();
	}

	cout << "±¹¾î ÃÑÁ¡: " << kr_sum << endl;
	cout << "±¹¾î Æò±Õ: " << kr_sum / 3 << endl;

	cout << "\n¿µ¾î ÃÑÁ¡: " << eng_sum << endl;
	cout << "¿µ¾î Æò±Õ: " << eng_sum / 3 << endl;

	cout << "\n¼öÇÐ ÃÑÁ¡: " << math_sum << endl;
	cout << "¼öÇÐ Æò±Õ: " << math_sum / 3 << endl;



	for (int i = 0; i < 3; i++)
	{
		//cout << "°´Ã¼ ÇÒ´ç ¼Ò¸êÀÚ È£Ãâ" << endl;
		delete gradeAry[i];
	}

	return 0;
}