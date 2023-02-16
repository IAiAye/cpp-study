#include <iostream>

using namespace std;

class Marine
{
private:
    static int total_marine_num; 
    const static int i = 0; // 다음과 같이 const static인 경우에만 초기화를 동시에 해줄 수 있다.

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
    static void show_total_marine(); // static 변수와 동일하게 static 함수 또한 클래스의 모든 객체에 존재한다. 따라서 클래스만으로도 호출이 가능하다.

    ~Marine() { total_marine_num--; }
};
int Marine::total_marine_num = 0; 
void Marine::show_total_marine()
{
    cout << "전체 마린 수 : " << total_marine_num << endl; // 그러므로 static 함수 속의 변수는 항상 static변수만이 들어갈 수 있다.
}


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
    Marine::show_total_marine();
}

int main()
{
    Marine marine1(2,3, 10);
    Marine::show_total_marine(); // 클래스로 함수를 호출하는 모습.
    
    Marine marine2(3,5, 15);
    marine2.show_total_marine(); // 객체에서도 호출이 가능하다.

    create_marine();

    cout << endl << "마린 1 이 마린 2 를 공격 ! " << endl;
    marine2.be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();
}