
#include <iostream>

using namespace std;

class Marine
{
private:
    static int total_marine_num; 
    const static int i = 0; 

    int hp;
    int coord_x, coord_y;
    bool is_dead;

    const int default_damage; 
public:
    Marine();
    Marine(int x, int y);
    Marine(int x, int y, int default_damage);

    int attack() const; // 상수 멤버 함수 선언.
    Marine& be_attacked(int damage_earn);
    void move(int x, int y);

    void show_status();
    static void show_total_marine(); 

    ~Marine() { total_marine_num--; }
};
int Marine::total_marine_num = 0; 
void Marine::show_total_marine()
{
    cout << "전체 마린 수 : " << total_marine_num << endl; 
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
int Marine::attack() const { return default_damage; } // 상수 함수 내에서는 다른 변수의 값을 바꾸지 않는 함수라고 명시할 수 있다.
// 따라서 상수함수 내에서는 읽기만이 수행되며 상수 함수 안에서는 상수함수만이 호출될 수 있다.
Marine& Marine::be_attacked(int damage_earn)
{
    
    this->hp -= damage_earn; 
    
    if (this->hp <= 0) this->is_dead = true;

    return *this; 
    
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
    Marine::show_total_marine(); 
    
    Marine marine2(3,5, 15);
    marine2.show_total_marine(); 

    create_marine();

    cout << endl << "마린 1 이 마린 2 를 두 번 공격 ! " << endl;
    marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack()); 

    marine1.show_status();
    marine2.show_status();
}