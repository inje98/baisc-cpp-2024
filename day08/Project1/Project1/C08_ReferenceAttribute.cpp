#include<iostream>
using namespace std;

class First
{
public:
	void FirstFunc() {
		cout << "FirstFunc()" << endl;
	}

	virtual void SimpleFunc()
	{
		cout << "First's SimpleFunc()" << endl;
	}
};

class Second : public First
{
public:
	void SecondFunc()
	{
		cout << "SecondFunc()" << endl;
	}

	virtual void SimpleFunc()
	{
		cout << "Second's SimpleFunc()" << endl;
	}
};

class Third : public Second
{
public:
	void ThirdFunc()
	{
		cout << "ThirdFunc()" << endl;
	}

	virtual void SimpleFunc()
	{
		cout << "Third's SimpleFunc()" << endl;
	}
};

int main(void)
{
	Third obj;
	obj.FirstFunc();
	obj.SecondFunc();
	obj.ThirdFunc();
	obj.SimpleFunc();

	Second& sref = obj;
	sref.FirstFunc();
	sref.SecondFunc();
	sref.SimpleFunc();

	First& fref = obj;
	fref.FirstFunc();
	fref.SimpleFunc();

	return 0;
} // obj니까 객체니까 SimpleFunc 이거 Third나오지 않나 이렇게 접근해보자

//FirstFunc()
//SecondFunc()
//ThirdFunc()
//Third's SimpleFunc()
// 
//FirstFunc()
//SecondFunc()
//Third's SimpleFunc()
// 
//FirstFunc()
//Third's SimpleFunc()