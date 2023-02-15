#include <iostream>

using namespace std;

class Marine
{
private:
    int hp;
    int coord_x, coord_y;
    int damage;
    int is_dead;

public:
    Marine();
    Marine(int x, int y);

    int attack();
    void be_attacked(int damage_earn);
    void move(int x, int y);

    void show_status();
};
Marine::Marine()
{
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
}
Marine::Marine(int x, int y)
{
    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
}
void Marine::move(int x, int y)
{
    coord_x = x;
    coord_y = y;
}
int Marine::attack(){ return damage; }
void Marine::be_attacked(int damage_earned)
{
    hp -= damage_earned;
    if (hp <= 0) is_dead = true;
}
void Marine::show_status()
{
    cout << "*** Marine ***" << endl;
    cout << "Location : ( " << coord_x << ", " << coord_y << " ) " << endl;
    cout << " HP : " << hp << endl;

}

int main()
{
    Marine* marines[100]; //배열로 쉽게 정리해버리기.

    marines[0] = new Marine(2, 3); // 객체를 동적으로 생성하면서 생성자도 호출해준다.
    marines[1] = new Marine(3, 5);

    marines[0]->show_status(); // 마린들의 포인터를 가르키는 배열이기때문에, ->로 호출해줘야한다.
    marines[1]->show_status();

    cout << endl << "마린 1 이 마린 2 를 공격! " << endl;
    marines[1]->be_attacked(marines[0]->attack());

    marines[0]->show_status();
    marines[1]->show_status();
}