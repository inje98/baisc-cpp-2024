// ��ü�迭

#include<iostream>

using namespace std;


class Human
{
	char name[30];
	int age;

public:
	Human(const char* iname, int iage)
	{
		cout << "������ ȣ��" << endl;

		strcpy(name, iname);
		age = iage;
	}

	~Human()
	{
		cout << "�Ҹ��� ȣ��" << endl;
	}

	void HumanInfo()
	{
		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
	}
};

int main()
{
	Human h[3] = { Human("ȫ�浿", 150), Human("¯��", 5), Human("�ͱ�", 5) };

	for (int i = 0; i < 3; i++)
	{
		h[i].HumanInfo();
	}

	Human* h1 = new Human("������", 50); // �� ������ Humanũ�⸸ŭ ���� �Ҵ�, �� ������ �����Ͱ�ü h1�� ����Ŵ
	h1->HumanInfo(); // �����Ͱ�ü�� ����Լ��� �����Ҷ�,  (->) �̰� ����

	return 0;
}