#pragma once
#include<iostream>
#include<cstring>

class Human
{
private:
	char name[10];
	int age;
	char job[10];

public:
	Human(const char* iname, int iage, const char* ijob);
	void humanInfo();
};
