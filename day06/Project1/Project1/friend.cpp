#include<iostream>
#include<cstring>
using namespace std;

# define _CTR_SECURE_NO_WARNINGS
// class Girl;

class Boy
{
private:
	int height;
	friend class Girl;

public:
	Boy(int len) :height(len){}
	
	void ShowYourFriendInfo(Girl & frn);

};

class Girl
{
private:
	char phNum[20];
public:
	Girl(const char* num)
	{
		strcpy_s(phNum, num);
	}

	void ShowYourFriendInfo(Boy& frn);
	friend class Boy;
};

void Boy::ShowYourFriendInfo(Girl& frn)
{
	cout << "Her Phon number: " << frn.phNum << endl;
}

void Girl::ShowYourFriendInfo(Boy& frn)
{
	cout << "His height: " << frn.height << endl;
}

int main(void)
{
	Boy boy(170);
	Girl girl("010-1234-5678");
	boy.ShowYourFriendInfo(girl);
	girl.ShowYourFriendInfo(boy);

	return 0;
}