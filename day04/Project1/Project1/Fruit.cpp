#include<iostream>

using namespace std;

class FruitSeller
{
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;

public:
	void InitMembers(int price, int num, int money) //초기화
	{
		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;
	}

	int SaleApples(int money) // 구매자가 준 돈을 받아 ==> 몇개 팔았냐
	{
		int num = money / APPLE_PRICE;   // 판매개수
		numOfApples -= num;				 // 남은 사과 갯수
		myMoney += money;				 // 번 돈
		return num;		// 몇개 팔았는지가 반환
	}

	void ShowSalesResult()
	{
		cout << "남은 사과: " << numOfApples << endl;
		cout << "판매 수익: " << myMoney << endl << endl;
	}

};

class FruitBuyer
{
	int myMoney;
	int numOfApples;

public:
	void InitMembers(int money) // 초기화 - 구매자의 돈
	{
		myMoney = money;
		numOfApples = 0;
	}

	void BuyApples(FruitSeller& seller, int money) // 판매자(객체)를 받아, 낸 돈도 받아
	{
		numOfApples += seller.SaleApples(money);
		myMoney -= money;
	}

	void ShowBuyResult()
	{
		cout << "현재 잔액: " << myMoney << endl;
		cout << "사과 개수: " << numOfApples << endl << endl;
	}
};


int main()
{
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0); // 사과 가격, 사과 개수, 내 돈
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000);

	cout << "과일 판매자의 현황" << endl;
	seller.ShowSalesResult();
	cout << "과일 구매자의 현황" << endl;
	buyer.ShowBuyResult();

	return 0;
}


