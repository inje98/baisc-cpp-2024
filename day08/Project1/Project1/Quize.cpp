#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
using namespace std;

// RemoteControl Ŭ����, SamsungTvŬ���� LgTvŬ������ �����ϰ�
//remote->on() ȣ���ϸ� ����� Tv�� ���� "�Ｚ TV ��" �Ǵ� "����TV ��"�� ��µǵ��� ���α׷� ¥��

class RemoteControl
{
public:
	RemoteControl()
	{}

	virtual void on()
	{
		cout << "TV�� �մϴ�" << endl;
	}
	void other()
	{
		cout << "Ƽ��" << endl;
	}
};

class SamsungTv : public RemoteControl
{
public:
	SamsungTv()
	{}

	void on()
	{
		cout << "�ＺTV on" << endl;
	}
	void other()
	{
		cout << "�Ｚ" << endl;
	}
};

class LGTv: public RemoteControl
{
public:
	LGTv()
	{}

	void on()
	{
		cout << "����TV on" << endl;
	}
	void other()
	{
		cout << "����" << endl;
	}
};


int main(void)
{
	// ���� RemoteControl Ŭ������ on�Լ��� virtual �������� "TV�� �մϴ�" �� ��µ�������
	RemoteControl* remote = new SamsungTv();
	remote->other();
	
	return 0;
}