// �̸� ���� ���� �ֹι�ȣ(�̴ϼȶ�����)


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
		cout << "�̸�: " << name << endl;
		cout << "����: " << job << endl;
		cout << "����: " << age << endl;
		cout << "�ֹ�: " << ID << endl;
	}
};


int main(void)
{
	Human h1("������", "���", 27, 980723);
	h1.HumanInfo();

	cout << '\n' << endl;

	Human h2("ȫ�浿", "����", 50, 505050);
	h2.HumanInfo();
	return 0;
}



