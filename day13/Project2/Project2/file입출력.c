/*
	File: file�����.c
	Created: 24-03-26
	Author: ������
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
		printf("Ʋ�Ƚ��ϴ�\n");
		printf("���Ḧ ���ϸ� 0\n�ٽ� �Է��Ϸ��� �ƹ�Ű�� ��������\n>> ");
		scanf("%d", &retry);
		getchar();

		if (retry == 0)
		{
			printf("�����մϴ�\n");
			exit(1);
		}
	}
}