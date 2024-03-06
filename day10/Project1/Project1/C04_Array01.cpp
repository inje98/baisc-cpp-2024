#include<iostream>
using namespace std;








int main(void)
{
	int arr[5] = { 1,2,3,4,5 };    // int형 배열 선언
	int *parr = arr;			   // 배열의 이름은 주소이다

	printf("arr 주소: %p\n", arr);
	printf("arr 크기: %d\n", sizeof(arr));  // int 크기 4 x 방 갯수 5 = 20 byte

	printf("arr[0] 주소: %p\n", &arr[0]);	
	printf("arr[1] 주소: %p\n", &arr[1]);	// arr[1]의 주소
	printf("arr + 1 : %p\n", arr + 1);		// arr이 배열의 첫번째 주소니까 거기에서 한칸(4byte) 띄면 arr[1]이 나오겠지

	printf("parr 주소 : %p\n", &parr);
	printf("parr 데이터 : %p\n", parr);		// parr은 배열 arr의 시작 주소를 저장하고 있다.
	printf("parr + 1 : %p\n", parr + 1);
	printf("parr[0] : %d\t*parr : %d\t arr[0] : %d", parr[0], *parr, arr[0]);

	return 0;
}