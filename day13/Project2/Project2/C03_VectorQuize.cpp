#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
	vector<int> score;
	
	while (1)
	{

		int inputScore;
		cout << "점수 입력 >> ";
		cin >> inputScore;

		score.push_back(inputScore);

		int sum = 0;
		for (vector<int>::size_type i = 0; i < score.size(); i++)
		{
			sum += score[i];
			/*printf("v[%d]: %d\n", i, v[i]);
			printf("v.at(i): %d\n", v.at(i));*/
		}

		cout << "평균: " << sum / score.size() << endl;




		/*vector<int>::iterator iter;
		int sum = 0;
		for (iter = score.begin(); iter != score.end(); iter++)
		{
			
			sum += score. 
		}*/

		/*
		vector<string>::iterator it;
		for (it = vs.begin(); it != vs.end(); it++)
		{
			cout << *it << endl;
		}
		*/

	}

	


	return 0;
}