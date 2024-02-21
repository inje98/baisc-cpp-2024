#include<iostream>

using namespace std;


int add(int a, int b)
{
	int result;
	result = a + b;

	return result;
}

int min(int a, int b)
{
	int result;
	result = a - b;

	return result;
}

int mul(int a, int b)
{
	int result;
	result = a * b;

	return result;
}

int divide(int a, int b)
{
	int result;
	result = a / b;

	return result;
}


int main()
{

	int input1, input2 = 0;

	char input3;

	int output = 0;
	
	cout << "두 수를 입력하세요 > ";
	cin >> input1 >> input2;
	cout << "받은 값 : " << input1 << " / " << input2 << endl;

	cout << "연산자를 입력하세요 > ";
	cin >> input3;

		if (input3 == '+')
		{
			output = add(input1, input2);
			cout << output << endl;
		}

		else if (input3 == '-')
		{
			output = min(input1, input2);
			cout << output << endl;
		}

		else if (input3 == '*')
		{
			output = mul(input1, input2);
			cout << output << endl;
		}

		else if (input3 == '/')
		{
			output = divide(input1, input2);
			cout << output << endl;
		}

		else
			cout << "잘못 입력한듯" << endl;

		return 0;
}