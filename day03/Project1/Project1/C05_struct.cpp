
// C++ Ŭ���� : Ŭ���� ����� ��� ������ ��� �Լ��� ������

#include<iostream>

class human       // human ����ü(���� ���� ����� ���� �ڷ���)
{
public:
	char name[20];
	int age;
	char job[20];

	void showHuman()    //��� : ����Լ�
	{
		printf("name: %s age: %d job: %s\n", name, age, job);   // iostream�� printf �� �� �ֳ�

	}
}; // ������ human ����ü�� Human���� ����ϰڴ�. �̷��� ���ϸ� struct human ��ߵ� ��������?


int main()
{
	int a = 10;
	//human h1 = { "ȫ�浿", 50, "����" }; //Human Ÿ���� ������ �����ϰ� �ʱ�ȭ�� ��Ų��
	//h1.showHuman()
	human h1 = { "ȫ�浿", 50, "����" };
	h1.showHuman();
	return 0;
}
