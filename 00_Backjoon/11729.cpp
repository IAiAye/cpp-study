#include <iostream>
using namespace std;

void hanoi(int n, int start, int to, int bypass)
{
    if (n == 1)
    {
        cout << start << ' ' << to << '\n';
    }
    else
    {
        hanoi(n - 1, start, bypass, to); // n - 1에선 중간 단계로 옮겨야한다.
        cout << start << ' ' << to << '\n'; // n 바닥인거 옮기기.
        hanoi(n - 1, bypass, to, start); // n - 1 탑을 다시 목적지로 옮기기.
    }
}

int main()
{
    int n;
    cin >> n;
    cout << (1<<n) - 1 << '\n';
    hanoi(n, 1, 3, 2);
}