#include<iostream>
using namespace std;





void Cal(int a, int b)
{
	if (!b) throw b;


	cout << "+: " << a + b << endl;
	cout << "-: " << a - b << endl;
	cout << "x: " << a * b << endl;
	cout << "/: " << a / b << endl;

}

int main(void)
{
	int n1, n2;

	cout << "정수 2개를 입력하세요 >> ";
	cin >> n1 >> n2;
	try
	{
		Cal(n1, n2);
	}

	catch (int exception)
	{
		cout << "0으로 나눌수 없습니다" << endl;
	}


	/*try
	{
		if (!n2) throw n2;
		cout << "/: " << n1 / n2 << endl;
	}
	catch (int exception)
	{
		cout << "0 으로 나눌수 없습니다." << endl;
	}*/





	return 0;
}