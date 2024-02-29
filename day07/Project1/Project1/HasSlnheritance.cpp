#include<iostream>
#include<cstring>
using namespace std;

class Gun
{
private:
	int bullet;

public:
	Gun(int bnum) : bullet(bnum)
	{}

	void Shot()
	{
		if (bullet > 1)
		{
			cout << "Bang!" << endl;
			bullet--;
		}
		else
		{
			bullet = 0;
			cout << "ÃÑ¾Ë ¾øÀ½!" << endl;
		}
	}

	int GetBullet()
	{
		return bullet;
	}
};

class Police : public Gun
{
private:
	int handcuffs;

public:
	Police(int bnum, int bcuff) : Gun(bnum), handcuffs(bcuff)
	{}

	void PutHandcuff()
	{
		if (handcuffs >= 1)
		{
			cout << "Snap!" << endl;
			handcuffs--;
		}
		else
		{
			handcuffs = 0;
			cout << "¼ö°© ¾øÀ½!" << endl;
		}
	}

	int GetHandcuffs()
	{
		return handcuffs;
	}

	void state()
	{
		cout << "\n³²Àº ÃÑ¾Ë : " << GetBullet() << endl;
		cout << "³²Àº ¼ö°© : " << GetHandcuffs() << endl << endl;
	}
};


//class Demon
//{
//private:
//	int Hp;
//
//public:
//	Demon(int hp) :Hp(hp)
//	{}
//};

int main(void)
{
	Police pman(5, 3);
	pman.state();

	pman.Shot();
	pman.PutHandcuff();

	pman.state();

	pman.Shot();
	pman.Shot();
	pman.Shot();
	pman.Shot();
	pman.Shot();


	pman.state();

	pman.PutHandcuff();
	pman.PutHandcuff();
	pman.PutHandcuff();
	pman.PutHandcuff();

	pman.state();



	return 0;
}