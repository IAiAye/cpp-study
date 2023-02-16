#include <iostream>

using namespace std;

class Marine
{
private:
    static int total_marine_num; // static 변수는 클래스의 모든 객체에서 공유되는 변수다.

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

    ~Marine() { total_marine_num--; }
};
int Marine::total_marine_num = 0; // 다음과 같이 초기화가 필요하다.
// 멤버 변수들을 클래스 내부에서 초기화시키지못하는 것처럼 static 변수 또한 클래스 내부에서 초기화 하는 것은 불가능하다.

Marine::Marine() : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
    total_marine_num++;
} 

Marine::Marine(int x, int y) : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {
    total_marine_num++;
} 

Marine::Marine(int x, int y, int default_damage) 
:   coord_x(x), 
    coord_y(y), 
    hp(50), 
    default_damage(default_damage), 
    is_dead(false) {
        total_marine_num++;
    } 

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
    cout << " 현재 총 마린 수 : " << total_marine_num << endl;
}

void create_marine()
{
    Marine marine3(10, 10, 4);
    marine3.show_status();
}

int main()
{
    Marine marine1(2,3, 10);
    marine1.show_status();
    
    Marine marine2(3,5, 15);
    marine2.show_status();

    create_marine();

    cout << endl << "마린 1 이 마린 2 를 공격 ! " << endl;
    marine2.be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();
}