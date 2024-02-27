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

	- 멤버 이니셜라이즈
		- 객체 생성전에 선언과 동시에 초기화가 필요한 경우에 사용한다.
		- const 변수와 참조변수의 초기화에 사용
	- int *pi) = new int;  // int 크기(4) 만큼 힙 영역에 공간을 할당, 할당 받은 메모리의 주소를 리턴

## 6일차

## 7일차

## 8일차

## 9일차

## 10일차
