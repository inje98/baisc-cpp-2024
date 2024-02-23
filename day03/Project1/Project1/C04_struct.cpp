#include<iostream>

typedef struct human       // human 구조체(내가 만든 사용자 정의 자료형)
{				   // 속성; 멤버변수(name, age, job)
	char name[20];
	int age;
	char job[20];

	void showHuman()    //기능 : 멤버함수
{
	printf("name: %s age: %d job: %s\n", name, age, job);   // iostream도 printf 쓸 수 있넹

}
}Human;   // 앞으로 human 구조체를 Human으로 사용하겠다. 이렇게 안하면 struct human 써야됨 쓸때마다?


int main()
{
	int a = 10;
	human h1 = { "홍길동", 50, "의적" }; //Human 타입의 변수를 선언하고 초기화를 시킨다
	h1.showHuman();
	
	return 0;
}
