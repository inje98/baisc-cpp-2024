#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int num;
	char c;

	printf("숫자를 입력하세요 : ");
	scanf("%d", &num);

	printf("문자를 입력하세요 : ");
	scanf("%c", &c);
	return 0;
}