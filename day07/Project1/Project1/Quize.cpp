#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;

class Myclass
{
private:
	string name;
	int age;
public:
	Myclass(string iname, int iage): age(iage)
	{
		name = iname;
	}

	string Myname()
	{
		return name;
	}

	int MyAge()
	{
		return age;
	}
};


class MyInfo : public Myclass
{
private:
	string pNumber;

public:
	MyInfo(string ipNumber, const char* iname, int iage) :Myclass(iname, iage)
	{
		pNumber = ipNumber;
	}

	string MyNum()
	{
		return pNumber;
	}

	void printMyInfo()
	{
		cout << "나의 이름은 " << Myname() << "이고 나이는 " << MyAge() << "살이며 전화번호는 " << MyNum() << "입니다" << endl;
	}
};

int main(void)
{
	MyInfo h1("010-8536-3347", "김인제", 27);
	h1.printMyInfo();

	return 0;
}