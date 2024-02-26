//�й� �̸� ���� ����
// �Է� 4���� �޴� ������
// studentInfo() ���� ���� ���
#include<iostream>


using namespace std;


class Student
{
private:
	const int ID;
	const char* name;
	char major[20];
	int age;

public:
	Student(int iID, const char* iname, const char* imajor, int iage) :ID(iID)  // ��� �̴ϼȶ�����(ID(iID)) �ʱ�ȭ��
	{// ��� �̴ϼȶ������ ��ü ������ �ʱ�ȭ���� �ʴ� ������� �ʱ�ȭ�Ҷ� ����Ѵ�. �� ��ü ������ ������� �̸� �ʱ�ȭ�� �Ǵ� ����鿡 �ʱ�ȭ
	// ���ڿ� => �ּ���!  �׷��� ������ ������ �־ ���
		name = iname;// "������","���ڰ���" ���ڿ� �ּҸ� name, major�� ����	
		strcpy_s(major, imajor);
		age = iage;
	}

	void studentInfo() const
	{
		cout << "�й�: " << ID << endl;
		cout << "�̸�: " << name << endl;
		cout << "����: " << major << endl;
		cout << "����: " << age << endl;
	}
};

int main(void)
{
	Student s1(20174266, "������", "���ڰ���", 27);
	s1.studentInfo();
}