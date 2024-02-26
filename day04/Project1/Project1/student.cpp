//학번 이름 전공 나이
// 입력 4개를 받는 생성자
// studentInfo() 만들어서 정보 출력
#include<iostream>


using namespace std;


class Student
{
private:
	const int ID;
	const char* name;
	char major[20];
	int age;

public:
	Student(int iID, const char* iname, const char* imajor, int iage) :ID(iID)  // 멤버 이니셜라이즈(ID(iID)) 초기화임
	{// 멤버 이니셜라이즈는 객체 생성시 초기화되지 않는 멤버들을 초기화할때 사용한다. 즉 객체 생성과 상관없이 미리 초기화가 되는 멤버들에 초기화
	// 문자열 => 주소임!  그래서 포인터 변수에 넣어서 사용
		name = iname;// "김인제","전자공학" 문자열 주소를 name, major에 복사	
		strcpy_s(major, imajor);
		age = iage;
	}

	void studentInfo() const
	{
		cout << "학번: " << ID << endl;
		cout << "이름: " << name << endl;
		cout << "전공: " << major << endl;
		cout << "나이: " << age << endl;
	}
};

int main(void)
{
	Student s1(20174266, "김인제", "전자공학", 27);
	s1.studentInfo();
}