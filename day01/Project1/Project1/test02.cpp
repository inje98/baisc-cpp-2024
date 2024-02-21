# include<iostream>

int main(void) 
{
	int num = 20;
	std::cout << "Hello World!" << std::endl; // 문자열은 큰따옴표, 문자는 작은따옴표
	std::cout << "Hello " << "World!" << std::endl;
	std::cout << num << ' ' << 'A';
	std::cout << ' ' << 3.14 << std::endl;

	return 0;
}