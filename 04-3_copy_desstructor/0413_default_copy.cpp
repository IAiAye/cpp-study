#include <string.h>
#include <iostream>

using namespace std;

class Photon_Cannon
{
private:
    int hp, shield;
    int coord_x, coord_y;
    int damage;

    char *name;

public:
    Photon_Cannon(int x, int y);
    Photon_Cannon(int x, int y, const char *cannon_name);
    Photon_Cannon(const Photon_Cannon &pc); // 1. 오류를 막기위해 디폴트가 아닌 복사생성자 만들어주기.

    void show_status();
    ~Photon_Cannon();
};

Photon_Cannon::Photon_Cannon(int x, int y)
{
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;

    name = NULL;
}
Photon_Cannon::Photon_Cannon(int x, int y, const char *cannnon_name)
{
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;

    name = new char[strlen(cannnon_name) + 1];
    strcpy(name, cannnon_name);
}
Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) // 2. 디폴트와 똑같지만 따로 작성해주면 깊은 복사가 일어난다.
{
    cout << "복사 생성자 호출 !" << endl;
    hp = pc.hp;
    coord_x = pc.coord_x;
    coord_y = pc.coord_y;
    shield = pc.shield;
    damage = pc.damage;

    name = new char[strlen(pc.name) + 1];
    strcpy(name, pc.name);
}
void Photon_Cannon::show_status()
{
    cout << "Photon Cannon : " << name << endl;
    cout << " Location : ( " << coord_x << ", " << coord_y << " ) " << endl;
    cout << " HP : " << hp << endl;
}
Photon_Cannon::~Photon_Cannon()
{
    if(name) delete[] name;
}

int main()
{
    Photon_Cannon pc1(3, 3, "Protoss");
    Photon_Cannon pc2(pc1);  // 복사되면서 pc2는 pc1과 같은 메모리를 가르킴.

    pc1.show_status();
    pc2.show_status();
}

/*
소멸자가 name이 있으면 delete를 해주게 되는데, pc1을 해제해주게 되면서
pc2에서 이미 해제된 메모리를 다시 접근해 해제하려고 할때 오류가 발생하게 되는 것이다.

이러한 오류는 메모리를 대입해주는 얕은 복사에서 일어나며 디폴트 복사 생성자에서 발생한다.
따라서 메모리를 새로 할당하여 내용을 복사하는 것인 깊은 복사가 필요하며 이는 직접 복사생성자를 만들어야한다.
*/