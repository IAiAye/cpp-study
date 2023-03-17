#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t;
    while (1)
    {
        cin >> t;
        cout << "입력 : " << t << '\n';

        if (cin.fail())// failbit, badbit 이 true일때 true 리턴.
        {
            cout << "제대로 입력해주세요." << '\n';
            cin.clear(); // flag 초기화.
            cin.ignore(100, '\n'); // 100자동안 개행문자가 나올때까지 버퍼에서 무시한다. 안해주면 버퍼에 문자가 남아있어 계속 반복.
        }
        if (t == 1) break;
    }
}