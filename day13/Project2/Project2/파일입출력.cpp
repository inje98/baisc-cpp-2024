#include<stdio.h>
#include<stdlib.h>

int main()
{
	char msg[10] = "김인제";
	FILE* fp;
	fp = fopen("import.txt", "w");
	if (fp == NULL)
	{
		fprintf(stderr, "Error");
		exit(1);
	}
	fprintf(fp, "%s", msg);
	printf("%s", msg);

	fclose(fp);


}

//int main()
//{
//	char msg[10] = "김인제";
//	FILE* fp;
//	fp = fopen("import.txt", "r");
//	if (fp == NULL)
//	{
//		fprintf(stderr, "Error");
//		exit(1);
//	}
//	fscanf(fp, "%s", msg);
//	printf("%s", msg);
//
//	fclose(fp);
//}

// 교재 30, 32 페이지