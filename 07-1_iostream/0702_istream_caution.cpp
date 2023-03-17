#include <iostream>
using namespace std;
int main()
{
    int t;
    while (cin >> t) // int 이외의 자료형이 들어왔을때 루프 탈출.
    {
        cout << "입력 : " << t << '\n';
        if (t == 0) break;
    }
    string s;
    cin >> s; // 위에서 루프를 탈출하는 경우 cin에 fail 비트가 켜져있는 상태이기때문에, 플래그를 초기화하지 않는 한 cin을 이용할수 없게 된다.
}
/*
ios 클래스에서 관리하는 스트림의 상태는 플래그 4개에 의해 관리된다.

goodbit : 스트림에 입출력 작업이 가능할 때

badbit : 스트림에 복구 불가능한 오류 발생시

failbit : 스트림에 복구 가능한 오류 발생시

eofbit : 입력 작업시에 EOF 도달시

*/