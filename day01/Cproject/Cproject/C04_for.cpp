#include<iostream>

using namespace std;

int main()
{
	int sum = 0; // 초기화 반드시 해줘야 함. 왜냐
	for (int i = 1; i <= 100; i++) {
		sum += i; // 얘가 sum = sum + 1 이잖아 rvalue에 sum에 값이 있어야 하니까.
	}
	cout << sum << endl;

	return 0;
}