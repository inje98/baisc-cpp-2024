#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
using namespace std;

// RemoteControl 클래스, SamsungTv클래스 LgTv클래스를 설계하고
//remote->on() 호출하면 연결된 Tv에 따라서 "삼성 TV 온" 또는 "엘지TV 온"이 출력되도록 프로그램 짜기

class RemoteControl
{
public:
	RemoteControl()
	{}

	virtual void on()
	{
		cout << "TV를 켭니다" << endl;
	}
	void other()
	{
		cout << "티비" << endl;
	}
};

class SamsungTv : public RemoteControl
{
public:
	SamsungTv()
	{}

	void on()
	{
		cout << "삼성TV on" << endl;
	}
	void other()
	{
		cout << "삼성" << endl;
	}
};

class LGTv: public RemoteControl
{
public:
	LGTv()
	{}

	void on()
	{
		cout << "엘지TV on" << endl;
	}
	void other()
	{
		cout << "엘지" << endl;
	}
};


int main(void)
{
	// 만약 RemoteControl 클래스에 on함수에 virtual 없었으면 "TV를 켭니다" 가 출력됐을거임
	RemoteControl* remote = new SamsungTv();
	remote->other();
	
	return 0;
}