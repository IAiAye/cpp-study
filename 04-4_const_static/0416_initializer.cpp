#include <iostream>

using namespace std;

class Marine
{
private:
    int hp;
    int coord_x, coord_y;
    bool is_dead;

    const int default_damage; // 상수를 써줄때 필요하다.
public:
    Marine();
    Marine(int x, int y);

    int attack();
    void be_attacked(int damage_earn);
    void move(int x, int y);

    void show_status();
};
Marine::Marine() : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {} //함수 본체에는 아무것도 없다. : 뒤로 오는 것을 초기화 리스트라고 부며 멤버 변수들을 초기화 시켜준다.

Marine::Marine(int x, int y) : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {} // 여기서 coord_x는 반드시 멤버 변수를 지칭한다.

/*
다음과 같이 하게 된다면 
int a = 10;
과 같이 생성과 초기화를 동시에 해주는 것이지만, 기존의 것은 생성 후에 따로 초기화 해주는 것이다.
또한 상수와 레퍼런스는 생성과 동시에 초기화가 되어야 하기때문에 이를 클래스 내부에서 쓰고싶다면 초기화 리스트를 사용해야만 한다.
*/

void Marine::move(int x, int y)
{
    coord_x = x;
    coord_y = y;
}
int Marine::attack() { return default_damage; }
void Marine::be_attacked(int damage_earn)
{
    hp -= damage_earn;
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
    Marine marine1(2,3);
    Marine marine2(3,5);

    marine1.show_status();
    marine2.show_status();

    cout << endl << "마린 1 이 마린 2 를 공격 ! " << endl;
    marine2.be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();
}