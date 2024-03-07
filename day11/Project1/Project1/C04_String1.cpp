#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	int code = 97;
	cout << code << endl;
	cout << (char)code << endl;
	cout << "======================" << endl;

	char ary[6] = { 'a', 'b', 'c', 'd', 'e' }; // 문자열 타입의 배열선언
	cout << ary << endl;
	cout << "========================" << endl;

	char ary1[] = { 'a', 'b', 'c', '\0', 'e' }; // 널문자, 문자열의 끝을 알려준다
	cout << ary1 << endl;
	cout << sizeof(ary) << endl;
	cout << sizeof(ary1) << endl; // 문자열 전체 크기, 첨부터 6칸 배정하면 그냥 6임 //전체 공간을 재준다

	cout << strlen(ary1) << endl; // 널문자 앞에까지의 크기, //문자열 길이를 재준다.
	cout << "========================" << endl;

	char str[] = "string";  // 이렇게 넣으면 자동으로 널문자가 붙는다
	cout << str << endl;
	cout << sizeof(str) << endl; // 그래서 이게 7이 나온다
	cout << strlen(str) << endl; // 널문자 앞에까지의 크기
	str[0] = 'S';
	cout << str << endl;
	cout << "========================" << endl;

	const char* pstr = "String";
	cout << pstr << endl;
	cout << sizeof(pstr) << endl;
	cout << strlen(pstr) << endl;
	//pstr[0] = 's'  문자열 포인터로 사용하는 경우 변경이 불가능하다

	cout << "========================" << endl;

	string s = "string";  // heap영역
	cout << s << endl;
	cout << sizeof(s) << endl;
	cout << s.size() << endl;
	return 0;
}