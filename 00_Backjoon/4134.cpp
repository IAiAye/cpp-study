#include <iostream>
using namespace std;

bool isPrime(unsigned int num)
{
    for (int i = 2; i * i <= num; i++)
    {
        if(num % i == 0) return false; // 루트 n까지 나눠지는 약수가 있다.
    }
    return true;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int t;
    unsigned int tmp;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> tmp;
        if (tmp == 0 || tmp == 1 || tmp == 2)
        {
            cout << 2 << '\n';
        }
        else
        {
            if (tmp % 2 == 0) tmp++;
            while (!isPrime(tmp)) tmp += 2;
            cout << tmp << '\n';
        }
    }
}