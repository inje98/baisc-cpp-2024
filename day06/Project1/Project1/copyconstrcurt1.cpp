#include<iostream>
#include<cstring>
using namespace std;


class Person {
private:
	char* name;   // �ʵ忡�� �̷� ���� ������ ��, �����Ҵ� �Ҷ�±��� ���� �ѹ� �غ��°͵� ��������?
	int age;
public:
	Person(const char* myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}


	Person(const Person& other) :age(other.age)
	{
		name = new char[strlen(other.name) + 1];  // �̷��� �ϸ� ���ο� ������ �Ҵ�Ǵϱ� 
		strcpy(name, other.name);				  // ��ġ ������ ����δϱ� ��ü1 �������� �̵��� �����ְ���
		cout << "��������� ȣ��" << endl;
	}

	void ShowPersonInfo() const
	{
		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
	}

	~Person()
	{
		delete[] name;
		cout << "called destructor!" << endl;
	}
};

int main(void)
{
	Person man1("Lee dong woo", 29);
	Person man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();

	return 0;
}