#include<iostream>

using namespace std;

class FruitSeller
{
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;

public:
	void InitMembers(int price, int num, int money) //�ʱ�ȭ
	{
		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;
	}

	int SaleApples(int money) // �����ڰ� �� ���� �޾� ==> � �Ⱦҳ�
	{
		int num = money / APPLE_PRICE;   // �ǸŰ���
		numOfApples -= num;				 // ���� ��� ����
		myMoney += money;				 // �� ��
		return num;		// � �ȾҴ����� ��ȯ
	}

	void ShowSalesResult()
	{
		cout << "���� ���: " << numOfApples << endl;
		cout << "�Ǹ� ����: " << myMoney << endl << endl;
	}

};

class FruitBuyer
{
	int myMoney;
	int numOfApples;

public:
	void InitMembers(int money) // �ʱ�ȭ - �������� ��
	{
		myMoney = money;
		numOfApples = 0;
	}

	void BuyApples(FruitSeller& seller, int money) // �Ǹ���(��ü)�� �޾�, �� ���� �޾�
	{
		numOfApples += seller.SaleApples(money);
		myMoney -= money;
	}

	void ShowBuyResult()
	{
		cout << "���� �ܾ�: " << myMoney << endl;
		cout << "��� ����: " << numOfApples << endl << endl;
	}
};


int main()
{
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0); // ��� ����, ��� ����, �� ��
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000);

	cout << "���� �Ǹ����� ��Ȳ" << endl;
	seller.ShowSalesResult();
	cout << "���� �������� ��Ȳ" << endl;
	buyer.ShowBuyResult();

	return 0;
}


