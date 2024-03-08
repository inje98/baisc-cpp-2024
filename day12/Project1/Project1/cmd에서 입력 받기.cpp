#include<iostream>
using namespace std;

int main(int argc, char* argv[])
{
	printf("argc: %d\n", argc);
	for (int i = 0; i < argc; i++)
	{
		printf("argv[%d]: %s\n", i, argv[i]);
	}

	printf("프로그램을 종료합니다\n");

	return 0;
}