#include <string.h>
#include <iostream>

using namespace std;

class Photon_Cannon
{
private:
    int hp, shield;
    int coord_x, coord_y;
    int damage;

public:
    Photon_Cannon(int x, int y);
    //Photon_Cannon(const Photon_Cannon& pc);

    void show_status();
    ~Photon_Cannon();
};
/*
Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) // 포톤캐논의 객체 pc를 상수 레퍼런스로 받는다. 이때 상수 레퍼런스로 받기때문에 pc의 값을 변경할수 없다.
{ // 변수의 내용을 변경할 일이 없다면 const로 받아주는 것이 바람직하다.
    cout << "복사 생성자 호출 !" << endl;
    hp = pc.hp;
    coord_x = pc.coord_x;
    coord_y = pc.coord_y;
    shield = pc.shield;
    damage = pc.damage;
    // 다음과 같은 내용을 쓰지않아도 디폴트 복사생성자가 자동으로 대응되는 원소를 자동으로 생성해준다. 주석처리를 해주어도 똑같이 기능하는 것을 확인할 수 있다.
}
*/
Photon_Cannon::Photon_Cannon(int x, int y)
{
    cout << "생성자 호출 !" << endl;
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;
}
void Photon_Cannon::show_status()
{
    cout << "Photon Cannon " << endl;
    cout << " Location : ( " << coord_x << ", " << coord_y << " ) " << endl;
    cout << " HP : " << hp << endl;
}
Photon_Cannon::~Photon_Cannon()
{
}

int main()
{
    Photon_Cannon pc1(3, 3);
    Photon_Cannon pc2(pc1); // 복사생성자 호출
    Photon_Cannon pc3 = pc2; // 이 문장도 위와 같이 복사생성자로 기능한다.

    pc1.show_status();
    pc2.show_status();
}