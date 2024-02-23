#include<iostream>
#include<cstring>

using namespace std;

namespace CAR_CONST
{
	enum
	{
		ID_LEN = 20,
		MAX_SPD = 200,
		FUEL_STEP = 2,
		ACC_STEP = 10,
		BRK_STEP = 10
	};
}


class Car
{
	// 멤버변수, 필드, 속성
private:

	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;

	// 멤버함수, 메서드, 기능
public:

	void InitMembers(const char* ID, int fuel);
	void ShowCarstate();
	void Accel();
	void Break();
};

void Car::InitMembers(const char* ID, int fuel)
{
	strcpy_s(gamerID, ID);  // 전달된 ID의 문자열을 gameID에 복사해서 저장
	fuelGauge = fuel;
	curSpeed = 0;
}

void Car::ShowCarstate()
{
	cout << "소유자ID: " << gamerID << endl;
	cout << "연료량:  " << fuelGauge << "%" << endl;
	cout << "현재속도: " << curSpeed << "km/s" << endl;

}
void Car::Accel()
{
	if (fuelGauge <= 0)
		return;
	else
		fuelGauge -= CAR_CONST::FUEL_STEP;

	if ((curSpeed + CAR_CONST::ACC_STEP) >= CAR_CONST::MAX_SPD)
	{
		curSpeed = CAR_CONST::MAX_SPD;
		return;
	}

	curSpeed += CAR_CONST::ACC_STEP;
}
void Car::Break()
{
	if (curSpeed < CAR_CONST::BRK_STEP)
	{
		curSpeed = 0;
		return;
	}
	curSpeed -= CAR_CONST::BRK_STEP;
}



int main(void)
{
	Car run99;
	run99.InitMembers("run99", 100);
	run99.Accel();
	run99.Accel();
	run99.Accel();
	run99.ShowCarstate();
	run99.Break();
	run99.ShowCarstate();

	return 0;
}