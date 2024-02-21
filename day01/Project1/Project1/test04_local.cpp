#include<iostream>

int main()
{
	int val1, val2;
	int result = 0;
	std::cout << "두개의 숫자입력: ";
	std::cin >> val1 >> val2;
	if (val1 < val2)
	{
		for (int i = val1 + 1; i < val2; i++)
			result += i;
	}
	else
	{
		for (int i = val2 + 1; i < val1; i++)
			result += i;

	}
	std::cout << "두 수 사이의 정수 합 : " << result << std::endl;
	return 0;
}


/*
	제어문

	1. 선택제어문
		if, swtich

	2. 반복제어문
		for, while
	
*/