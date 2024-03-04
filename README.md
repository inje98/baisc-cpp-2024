# baisc-cpp-2024
# 심화 프로그래밍 2024
IoT 개발자 심화 프로그래밍 언어 학습리포지토리

## 1일차
- 개발환경 설치
	- Visual Studio 2022 Community 설치
	- C++ 소스코드 실행
	
- c++ 기본
	- 변수, 함수, 자료형 
	- 입출력(cout, cin), 지역/전역 변수
	- 제어문
		- if
		- switch
		
	- 반복문
		- for
		- while
		
	- 함수 오버로딩
		- 함수 이름 같아도 매개변수 갯수, 매개변수 타입이 다르면 다른 함수처럼 쓸 수 있음
		
## 2일차
- C++
	- 매개변수 디폴트
	- 인라인 함수(inline)
		- 전처리기(#define)의 개념
		
	- 이름공간(NameSpace)
		- NameSpace 팀 작업할때, 팀 별로 같은 이름의 변수 쓸 수 있도록
		
	- 포인터: 주소
	- 참조자: 변수명
	
	- const
		- 상수화: const int a = 10;
			- const int &ref = 30;
	- 메모리
		- 스택
			- 지역변수, 매개변수
		- heap
			- 사용자에게 할당된 영역
			- malloc() 할당, free() 반환
		- 데이터
			- 함수, 전역변수, 상수, 문자리터널
			
## 3일차
- C++
	- 동적할당
		- C
			- malloc()할당, free()반환
		- C++
			- new 할당, delete 반환
			- 힙 영역에 내가 원하는 만큼 메모리 동적할당
			- 쓰고 나면 delete로 반환
			
	- 구조체(Strcuct)
	
	- 클래스
		- 메서드 : 클래스 안의 함수처럼
		- 멤버변수 : 클래스 안의 변수
		- private
			- 일반적으로 멤버변수는 private에
		- public
			- 멤버함수 정의, 접근제한을 사용한다
		
	- 파일 분할 : 파일을 나눠서 코드를 작성한다
		- 헤더파일  
			- 클래스 선언(#pragma once)
		- CPP1 
			- 메인함수(#include "헤더파일.h")
		- CPP2 
			- 함수 정의 부분(#include "헤더파일.h")
			
## 4일차
- C++
	- 정보은닉
		- private에 멤버변수 선언
		- 그 변수에 접근하는 함수를 별도로 정의
		- 이렇게 안전하게 변수에 접근할 수 있다.
		- 함수(~~) const
		{
		 ~~
		}
		
	- 생성자
		- 클래스 이름하고 같다
		- 주로 초기화 담당
		- 객체가 생성되면 자동으로 호출된다.
		

## 5일차
- C++
	- 멤버 이니셜라이즈
		- 객체 생성전에 선언과 동시에 초기화가 필요한 경우에 사용한다.
		- const 변수와 참조변수의 초기화에 사용
		
	- int *pi = new int;  
			- int 크기(4) 만큼 힙 영역에 공간을 할당, 할당 받은 메모리의 주소를 리턴
			
	- 포인터 배열
		- 포인터를 저장하는 배열
	- 배열 포인터
		- 배열을 가리키는 포인터
	- this 포인터
		- 객체 자신의 주소값
		- 그니까 *this는 객체 자기자신이다
	
	- 복사 생성자
		- 객체를 복사할때 호출되는 생성자
		- 따라서 복사 객체를 입력으로 가져야 하는데 이때 원본 객체의 참조를 입력으로 받는다
			- A( A& obj ){...}
			
## 6일차
- C++
	- 복사생성자가 호출되는 3가지 경우
		1. 객체가 복사될때 
			- Human H1 = H2;
		2. Human(const Person& copy)  
			- 저 copy에 오는 매개객체를 copy가 복사하면서 호출
		3. return 객체
			- return으로 반환된 객체를 바깥쪽 함수에서 받을때 임시객체 생성하면서 거기다 복사할때 호출

	- 얕은복사와 깊은복사의 개념
		- 얕은복사 했다가 동적할당에서 생기는 문제점
			- delete 했을때 같이 가리키던 힙영역 삭제 되던거 => 파일보고 정리
			
	- friend
		- 클래스 A가 클래스 B를 friend 삼으면 B는 A안에 있는 private 변수에 접근할 수가 있다.
		
	- static
		- 함수 내에 선언된 static의 의미
			- 한번만 초기화 되고, 지역변수와 달리 함수를 빠져나가도 소멸되지 않는다
			- 그럼 전역변수하고는 뭐가 다르냐
				- 다른 지역에선 사용이 안된다.
		- 전역변수에 선언된 static의 의미
			- 선언된 파일 내에서만 참조를 허용하겠다는 의미
				- 1.cpp의 int a 와 2.cpp의 int a 는 다른 녀석이라는거인듯
				
## 7일차
- C++
	- static
		- 클래스 안에 있는 멤버변수(함수)는 객체를 생성해야지만 그 객체를 통해 접근 가능했다
		- 근데 클래스안에 static 변수가 있으면 객체로 접근은 물론, 클래스로도 접근할 수 있다.
		- 원래 객체 h1, h2, h3에서 만든 변수 a는 다 다른 변수라면, static변수는 h1, h2, h3 다 공유한다.
		
	- static int func() {... 여기선 static 변수만 접근 가능...}
	
	- mutable
		- const 상수화 한 함수내의 값을 예외적으로 바꿀 수 있다.
			- void func() const{num1 = num2}  -> num1이 mutable num1 이라면 변경 가능
	- 상속
		- 자식 클래스가 부모 클래스를 쓸 수 있다

## 8일차
- C++
	- 객체 포인터의 참조관계
		- 부모 객체 포인터로 자식 객체를 가리킬 수 있다. ParentClass* Parent = new SonClass()
		- 반대는 불가능
		
	- 오버로딩(overloading) : 함수이름 같고 매개변수 다른거
	- 오버라이딩(overriding) : 재정의. 상속관계에서 사용

	- 가상함수(Virtual)  ==> day08 C06_Virtual.cpp 보면 이해될듯, 왜 이게 필요한지 필요성을 이해하자.
			- Base* pb = new Derived();
			- 이런 경우 Base 중심이 아니라 '객체'인 Derived 따라서 함수를 쓰는거임! 이해 안되면 파일보고 정리

	- 순수가상함수
		- 클래스 안에 virtual int GetPay() const = 0; 이런 식으로 (virtual 에 = 0;) 이런 형태이다.
		- 실제로 0을 넣는다는 의미가 아니라 컴파일러에 '나는 가상함수입니다' 알려준다 생각하면 될듯
		- 순수 가상합수를 가지고 있는 함수는 객체를 생성할 수 없다.
		- 순수 가상함수를 가지고 있는 클래스를 '추상클래스' 라고 한다.
	
## 9일차

## 10일차
