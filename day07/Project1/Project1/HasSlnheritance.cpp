#include<iostream>
#include<cstring>
using namespace std;

class Gun {
private:
    int bullet;

public:
    Gun(int bnum) : bullet(bnum) {}

    void Shot() {
        if (bullet > 0) {
            cout << "Bang!" << endl;
            bullet--;
        }
        else {
            cout << "총알 없음!" << endl;
        }
    }

    int GetBullet() {
        return bullet;
    }
};

class Enemy {
private:
    int hp;

public:
    Enemy(int health) : hp(health) {}

    void TakeDamage(int damage) {
        hp -= damage;
        cout << "적 체력 감소! 현재 체력: " << hp << endl;
    }

    int GetHP() {
        return hp;
    }
};

class Police : public Gun {
private:
    int handcuffs;

public:
    Police(int bnum, int bcuff) : Gun(bnum), handcuffs(bcuff) {}

    void PutHandcuff() {
        if (handcuffs >= 1) {
            cout << "Snap!" << endl;
            handcuffs--;
        }
        else {
            cout << "수갑 없음!" << endl;
        }
    }

    int GetHandcuffs() {
        return handcuffs;
    }

    void state() {
        cout << "\n남은 총알 : " << GetBullet() << endl;
        cout << "남은 수갑 : " << GetHandcuffs() << endl << endl;
    }

    // 경찰이 총을 쏠 때 적에게 데미지를 입히는 함수
    void ShootEnemy(Enemy& target) {
        cout << "경찰이 총을 쏩니다!" << endl;
        Shot(); // 총을 쏘고
        target.TakeDamage(1); // 적에게 데미지를 입힘
    }
};

int main(void) {
    // 객체 생성
    Police pman(5, 3);
    Enemy enemy(10);

    // 초기 상태 출력
    pman.state();
    cout << "적의 초기 체력: " << enemy.GetHP() << endl;

    // 경찰이 총을 쏘고 상태 출력
    pman.ShootEnemy(enemy);
    pman.state();
    cout << "적의 현재 체력: " << enemy.GetHP() << endl;

    return 0;
}
