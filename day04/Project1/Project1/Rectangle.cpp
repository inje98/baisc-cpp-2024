#include<iostream>
using namespace std;

class Point
{
public:
	int x;
	int y;
};

class Rectangle
{
public:
	Point upLeft;
	Point lowRight;

public:
	void ShowRecinfo()
	{
		cout << "�� ���: " << '[' << upLeft.x << ", ";
		cout << upLeft.y << ']' << endl;
		cout << "�� �ϴ�: " << '[' << lowRight.x << ", ";
		cout << lowRight.y << ']' << endl << endl;
	}
};

int main()
{
	Point pos1 = { -2, 4 };
	Point pos2 = { 5, 9 };
	Rectangle rec = { pos2, pos1 };
	rec.ShowRecinfo();
	return 0;
}