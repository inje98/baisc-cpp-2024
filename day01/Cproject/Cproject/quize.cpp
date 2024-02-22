#include<iostream>
#include<limits>

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

float divide(float a, float b)
{
	float result;
	result = a / b;

	return result;
}


int main()
{

	while (1) {



		int input1, input2;

		char input3;

		int output;

		cout << "첫번째 수 > ";
		cin >> input1;
		if (cin.fail()) {
			cout << "올바른 정수를 입력하세요." << endl;
			cin.clear();  // 에러 상태를 지움
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 버퍼의 잘못된 입력을 무시
			continue;  // 다음 반복으로 이동
		}
		cout << "받은 값 : " << input1 << endl;



		cout << "연산자를 입력하세요 > ";
		cin >> input3;

		if (input3 == '+' || input3 == '-' || input3 == '*' || input3 == '/')
		{
			cout << input1 << " " << input3 << endl;
		}
		else {
			cout << "+, -, *, / 중에 쓰세요. 첨부터 다시 쓰셈!" << endl;
			continue;
		}

		cout << "두번째 수 > ";
		cin >> input2;
		if (cin.fail()) {
			cout << "올바른 정수를 입력하세요. 첨부터 다시" << endl;
			cin.clear();  // 에러 상태를 지움
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 버퍼의 잘못된 입력을 무시
			continue;  // 다음 반복으로 이동
		}
		cout << "받은 값 : " << input2 << endl;






		if (input3 == '+')
		{
			output = add(input1, input2);
			cout << "\n\n\n" << input1 << input3 << input2 << '=' << output << "\n\n\n" << endl;
		}

		else if (input3 == '-')
		{
			output = min(input1, input2);
			cout << "\n\n\n" << input1 << input3 << input2 << '=' << output << "\n\n\n" << endl;
		}

		else if (input3 == '*')
		{
			output = mul(input1, input2);
			cout << "\n\n\n" << input1 << input3 << input2 << '=' << output << "\n\n\n" << endl;
		}

		else if (input3 == '/')
		{
			float dival;
			dival = divide((float)input1, (float)input2);
			cout << "\n\n\n" << input1 << input3 << input2 << '=' << dival << "\n\n\n" << endl;
		}


	}

	return 0;
}