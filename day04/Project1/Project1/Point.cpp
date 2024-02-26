#include<iostream>
#include "Point.h"


using namespace std;


bool Point::InitMembers(int xpos, int ypos)
{
	if (xpos < 0 || ypos < 0) 
	{
		cout << "벗어난 범위의 값 전달" << endl;
		return false;
	}

	x = xpos;
	y = ypos;
	return true;
}

int Point::GetX() const     // 함수를 상수화 // 보통 이런 형태는 읽기 전용에서 많이 쓰는듯
{							// 이렇게 안하면 함수 안에 변수(여기서는 x) 값이 바뀔수도 있겠지
	return x;
}

int Point::GetY() const
{
	return y;
}

bool Point::SetX(int xpos)
{
	if (0 > xpos || xpos > 100) {
		cout << "벗어난 범위의 값 전달" << endl;
		return false;
	}

	x = xpos;
	return true;
}

bool Point::SetY(int ypos)
{
	if (0 > ypos || ypos > 100)
	{
		cout << "벗어난 범위의 값 전달" << endl;
		return false;
	}
	y = ypos;
	return true;
}