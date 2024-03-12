#include<iostream>
using namespace std;

int main(void)
{
	char ary[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	int count = 0;


	
	while (1)
	{
		bool Finish = true;

		if (ary[0] < ary[1])
		{
			char temp;
			temp = ary[0];
			ary[0] = ary[1];
			ary[1] = temp;
			Finish = false;
		}

		if (ary[1] < ary[2])
		{
			char temp;
			temp = ary[1];
			ary[1] = ary[2];
			ary[2] = temp;
			Finish = false;

		}

		if (ary[2] < ary[3])
		{
			char temp;
			temp = ary[2];
			ary[2] = ary[3];
			ary[3] = temp;
			Finish = false;

		}

		if (ary[3] < ary[4])
		{
			char temp;
			temp = ary[3];
			ary[3] = ary[4];
			ary[4] = temp;
			Finish = false;

		}

		if (ary[4] < ary[5])
		{
			char temp;
			temp = ary[4];
			ary[4] = ary[5];
			ary[5] = temp;
			Finish = false;

		}

		count++;

		if (Finish == true)
		{
			break;
		}
	}

	for (int i = 0; i < count; i++)
	{
		cout << ary[i] << endl;
	}

	


		

	/*while (1)
	{
		
	



	}*/



	return 0;
}