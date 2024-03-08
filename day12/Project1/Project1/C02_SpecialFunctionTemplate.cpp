#include<iostream>
#include<cstring>
using namespace std;

template<typename T>
T Max(T a, T b)
{
	return a > b ? a : b;
}

template<>
const char* Max(const char* a, const char* b)
{
	cout << "char* Max(const char* a, const char* b)" << endl;
	cout << a << endl;
	return strcmp(a, b) > 0 ? a : b;
}

int main(void)
{
	/*int a = strcmp("Simple", "Best");
	cout << a << endl;*/



	cout << Max(11, 15) << endl;
	cout << Max('T', 'Q') << endl;
	cout << Max(3.5, 7.5) << endl;
	cout << Max("Simple", "Best") << endl;

	char str1[] = "Simple";
	char str2[] = "Best";
	cout << Max(str1, str2) << endl;

	// cout << (int)'T' << (int)'Q' << endl;
	return 0;

}