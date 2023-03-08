#include <iostream>
#include <string>
using namespace std;

class Base
{
protected: // 상속받는 클래스에서만 접근 가능하다.
    string parent_string;

public:
    Base() : parent_string("기반") { cout << "기반 클래스" << endl; }

    void what() { cout << parent_string << endl; }
};

class Derived : public Base
{
private:
    string child_string;

public:
    Derived() : Base(), child_string("파생") 
    {
        cout << "파생 클래스" << endl;

        // 이때 기반 클래스의 private은 파생 클래스에서도 접근이 불가능하다. 이를 위해 중간 단계가 필요하다.
        parent_string = "바꾸기";
    }
    void what() { cout << child_string << endl; } 
};
int main()
{
    cout << " === 기반 클래스 생성 === " << endl;
    Base p;
    cout << " === 파생 클래스 생성 === " << endl;
    Derived c; 

    return 0;
}

/*
private : (부모님들한테 안가르쳐 주는) 자신만의 비밀번호

protected : 집 현관문 비밀번호 ( 가족들은 알지만 그 외의 사람들은 접근불가)

public : 집 주소 (가족 뿐만이 아니라 다른 사람들도 알 수 있다)
*/

/*
만일 위처럼 public 형태로 상속 하였다면 기반 클래스의 접근 지시자들에 영향 없이 그대로 작동합니다. 
즉 파생 클래스 입장에서 public 은 그대로 public 이고, protected 는 그대로 protected 이고, private 은 그대로 private 입니다.

만일 protected 로 상속하였다면 파생 클래스 입장에서 public 은 protected 로 바뀌고 나머지는 그대로 유지됩니다.

만일 private 으로 상속하였다면 파생 클래스 입장에서 모든 접근 지시자들이 private 가 됩니다.
*/