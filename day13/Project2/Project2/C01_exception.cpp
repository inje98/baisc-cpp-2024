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

	cout << "���� 2���� �Է��ϼ��� >> ";
	cin >> n1 >> n2;
	try
	{
		Cal(n1, n2);
	}

	catch (int exception)
	{
		cout << "0���� ������ �����ϴ�" << endl;
	}


	/*try
	{
		if (!n2) throw n2;
		cout << "/: " << n1 / n2 << endl;
	}
	catch (int exception)
	{
		cout << "0 ���� ������ �����ϴ�." << endl;
	}*/





	return 0;
}