//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	char msg[10] = "������";
//	FILE* fp;
//	fp = fopen("import.txt", "w");
//	if (fp == NULL)
//	{
//		fprintf(stderr, "Error");
//		exit(1);
//	}
//	fprintf(fp, "%s", msg);  // msg�� ���� fp�ȿ� �ִ´�
//	printf("%s", msg);
//
//	fclose(fp);
//
//	char _msg[20];
//	FILE* _fp;
//	if ((_fp = fopen("KIm.txt", "r")) == NULL)
//	{
//		fprintf(stderr, "ERROR");
//		exit(1);
//	}
//
//	fscanf(_fp, "%s", _msg);  // _fp���� �����͸� _msg�� �ִ´�
//	//printf("%s", _msg);
//
//	if ((_fp = fopen("Kim_copy.txt", "w")) == NULL)
//	{
//		fprintf(stderr, "Error");
//		exit(1);
//	}
//
//	fprintf(_fp, "%s", _msg);
//	printf("%s", _msg);
//
//	fclose(_fp);
//}


// �̰� �� ������?
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char msg[10] = "������";
	FILE* fp;
	fp = fopen("import.txt", "w");
	if (fp == NULL)
	{
		fprintf(stderr, "Error");
		exit(1);
	}
	fprintf(fp, "%s", msg);  // msg�� ���� fp�ȿ� �ִ´�
	printf("%s", msg);


	if ((fp = fopen("Kim.txt", "r")) == NULL)
	{
		fprintf(stderr, "ERROR");
		exit(1);
	}

	fscanf(fp, "%s", msg);  // _fp���� �����͸� _msg�� �ִ´�
	//printf("%s", _msg);

	if ((fp = fopen("Kim_copy.txt", "w")) == NULL)
	{
		fprintf(stderr, "Error");
		exit(1);
	}

	fprintf(fp, "%s", msg);
	printf("%s", msg);

	fclose(fp);
}