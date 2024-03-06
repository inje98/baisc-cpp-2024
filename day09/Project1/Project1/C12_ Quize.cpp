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
// 멤버함수 안에 쓸려면 반드시 a.opperator+() 이 형태밖에 안되니까 100 + a 이런건 멤버안에선 절대 안됨. 그래서 밖으로 나와서
// operator+(int value, const Point& ref) 이렇게 쓰는거. 
// 이게 (정수 + 객체) 임

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

