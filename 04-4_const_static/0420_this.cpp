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

    int attack();
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
int Marine::attack() { return default_damage; }
Marine& Marine::be_attacked(int damage_earn)
{
    //hp -= damage_earn;
    this->hp -= damage_earn; // 따라서 다음과 똑같다고 할 수 있다.
    //if (hp <= 0) is_dead = true;
    if (this->hp <= 0) this->is_dead = true;

    return *this; // 객체 자신을 가리키는 포인터. 즉, 이 멤버 함수를 호출하는 객체 자신을 가리킨다.
    // 따라서 Marine& 을 리턴하는 것이다. 이는 레퍼런스를 리턴해주는 것이다.
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
    marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack()); // 즉, 첫 be_attacked에서 함수가 실행된 후 marine2가 리턴되고 또 한번 함수를 실행 할수 있는 것이다.

    marine1.show_status();
    marine2.show_status();
}