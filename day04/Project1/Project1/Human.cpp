// 이름 직업 나이 주민번호(이니셜라이즈)


#include<iostream>

using namespace std;

class Human
{
private:
	char name[20];
	char job[20];
	const int age;
	const int ID;

public:
	Human(const char* iname, const char* ijob, int iage, int iID) :age(iage), ID(iID)
	{
		strcpy_s(name, iname);
		strcpy_s(job, ijob);
	}
	void HumanInfo()
	{
		cout << "이름: " << name << endl;
		cout << "직업: " << job << endl;
		cout << "나이: " << age << endl;
		cout << "주민: " << ID << endl;
	}
};


int main(void)
{
	Human h1("김인제", "백수", 27, 980723);
	h1.HumanInfo();

	cout << '\n' << endl;

	Human h2("홍길동", "의적", 50, 505050);
	h2.HumanInfo();
	return 0;
}



