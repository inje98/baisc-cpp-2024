// 객체배열

#include<iostream>

using namespace std;


class Human
{
	char name[30];
	int age;

public:
	Human(const char* iname, int iage)
	{
		cout << "생성자 호출" << endl;

		strcpy(name, iname);
		age = iage;
	}

	~Human()
	{
		cout << "소멸자 호출" << endl;
	}

	void HumanInfo()
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
};

int main()
{
	Human h[3] = { Human("홍길동", 150), Human("짱구", 5), Human("맹구", 5) };

	for (int i = 0; i < 3; i++)
	{
		h[i].HumanInfo();
	}

	Human* h1 = new Human("가나다", 50); // 힙 영역에 Human크기만큼 공간 할당, 그 공간을 포인터객체 h1이 가리킴
	h1->HumanInfo(); // 포인터객체가 멤버함수에 접근할땐,  (->) 이거 쓴다

	return 0;
}