#include <iostream>

using namespace std;

class Marine
{
private:
    int hp;
    int coord_x, coord_y;
    bool is_dead;

    const int default_damage; 
public:
    Marine();
    Marine(int x, int y);
    Marine(int x, int y, int default_damage);

    int attack();
    void be_attacked(int damage_earn);
    void move(int x, int y);

    void show_status();
};
Marine::Marine() : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {} 

Marine::Marine(int x, int y) : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {} 

Marine::Marine(int x, int y, int default_damage)  // damage를 인자로 받아 변경할 수 도 있다.
:   coord_x(x), 
    coord_y(y), 
    hp(50), 
    default_damage(default_damage), 
    is_dead(false) {} 

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
    Marine marine1(2,3, 10);
    Marine marine2(3,5, 15);

    marine1.show_status();
    marine2.show_status();

    cout << endl << "마린 1 이 마린 2 를 공격 ! " << endl;
    marine2.be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();
}