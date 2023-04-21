#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long a, b, c;
int cnt;

long long multi(int b)
{
    if (b == 1)
    {
        cnt++;
        return a % c;
    }
    long long tmp = multi(b / 2);
    tmp = tmp * tmp % c; // a^b = a^b/2 * a^b/2

    if (b % 2 == 1) return tmp * a % c; // b가 홀수일 경우, a를 한 번 더 곱해줌.
    else return tmp;   
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> c;
    cout << multi(b) << '\n';

    return 0;
}