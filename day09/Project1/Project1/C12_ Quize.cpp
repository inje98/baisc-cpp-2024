#include<iostream>
using namespace std;

class Point
{
private:
	int num1, num2;

public:
	Point(int num1, int num2): num1(num1), num2(num2)
	{}



	Point operator+(int value)
	{
		Point result(num1 + value, num2 + value);
		return result;
	}

	Point operator+(const Point& ref) 
	{															 
		Point result(num1 + ref.num1, num2 + ref.num2);
		return result;		
	}

	void viewPoint()
	{
		cout << num1 << ", " << num2 << endl;
	}

	friend Point operator+(int value, const Point& ref);
};

Point operator+(int value, const Point& ref)
{
	Point result(ref.num1 + value, ref.num2 + value);
	return result;
}
// ����Լ� �ȿ� ������ �ݵ�� a.opperator+() �� ���¹ۿ� �ȵǴϱ� 100 + a �̷��� ����ȿ��� ���� �ȵ�. �׷��� ������ ���ͼ�
// operator+(int value, const Point& ref) �̷��� ���°�. 
// �̰� (���� + ��ü) ��

class ostream
{

};


int main(void)
{
	Point a(10, 20);
	Point b(30, 40);
	Point c = a + b; // a.operator+(b)
	Point d = a + 100; // a.operator+(100)
	Point e = 100 + a; //operator+(100, a);


	a.viewPoint();
	b.viewPoint();
	c.viewPoint();
	d.viewPoint();
	e.viewPoint();


	cout << c << endl;
	cout << d << endl;
	cout << e << endl;

	return 0;
}

