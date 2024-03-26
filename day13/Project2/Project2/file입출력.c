/*
	File: file입출력.c
	Created: 24-03-26
	Author: 김인제
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
	char ID[40];
	char PW[40];

	char MyID[] = "Kim";
	char MyPW[] = "123";

	while (1)
	{

		printf("ID >> ");
		scanf("%s", ID);
		printf("PW >> ");
		scanf("%s", PW);

		if (strcmp(ID, MyID) == 0 && strcmp(PW, MyPW) == 0)
		{
			char msg[40];
			FILE* fp;
			if ((fp = fopen("myinfo.txt", "r")) == NULL)
			{
				fprintf(stderr, "ERROR");
				exit(1);
			}
			fscanf(fp, "%s", msg);
			printf("%s\n", msg);

			fclose(fp);
			break;
		}
		int retry = -1;
		printf("틀렸습니다\n");
		printf("종료를 원하면 0\n다시 입력하려면 아무키나 누르세요\n>> ");
		scanf("%d", &retry);
		getchar();

		if (retry == 0)
		{
			printf("종료합니다\n");
			exit(1);
		}
	}
}