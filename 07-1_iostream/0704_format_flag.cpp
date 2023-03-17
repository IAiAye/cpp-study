#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t;
    while (1)
    {
        // cin.setf(ios_base::hex, ios_base::basefield); //스트림의 설정을 바꾸어준다. basefield의 값을 16진법(hex)로 초기화 시켜준 것이다.
        // cin >> t;
        cin >> hex >> t; // 다음과 같이도 16진법을 받을수 있는데, 입력 혹은 출력 방식을 바꿔주는 함수를 조작자라고 한다. 
        // 위의 방법은 형식 플래그라고 하고, 아래의 방법은 조작자라고 한다.
        // 두 가지의 방법은 완전 다른 방식이다. 위는 단순한 상수 값이며, 아래는 함수이다.
        cout << "입력 : " << t << '\n';

        if (cin.fail())
        {
            cout << "제대로 입력해주세요." << '\n';
            cin.clear(); 
            cin.ignore(100, '\n'); 
        }
        if (t == 1) break;
    }
}
/*
이러한 조작자에는 여러가지가 있는데, boolalpha, left, right 등이 있고,
endl 또한 이에 포함된다.
문자 1개를 내보낸다고 바로 출력되는 것이 아니라 버퍼에 모았다가 출력이 되는데 이때 flush을 이용한다면 버퍼에 저장하지 않고 바로 출력해준다.
endl은 '\n'과 flush를 합친 것이라고 볼 수 있다.
*/