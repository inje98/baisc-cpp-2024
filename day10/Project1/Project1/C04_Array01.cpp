#include<iostream>
using namespace std;








int main(void)
{
	int arr[5] = { 1,2,3,4,5 };    // int�� �迭 ����
	int *parr = arr;			   // �迭�� �̸��� �ּ��̴�

	printf("arr �ּ�: %p\n", arr);
	printf("arr ũ��: %d\n", sizeof(arr));  // int ũ�� 4 x �� ���� 5 = 20 byte

	printf("arr[0] �ּ�: %p\n", &arr[0]);	
	printf("arr[1] �ּ�: %p\n", &arr[1]);	// arr[1]�� �ּ�
	printf("arr + 1 : %p\n", arr + 1);		// arr�� �迭�� ù��° �ּҴϱ� �ű⿡�� ��ĭ(4byte) ��� arr[1]�� ��������

	printf("parr �ּ� : %p\n", &parr);
	printf("parr ������ : %p\n", parr);		// parr�� �迭 arr�� ���� �ּҸ� �����ϰ� �ִ�.
	printf("parr + 1 : %p\n", parr + 1);
	printf("parr[0] : %d\t*parr : %d\t arr[0] : %d", parr[0], *parr, arr[0]);

	return 0;
}