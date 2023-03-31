#include <iostream>
#include <set>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int cnt, tmp;
    set <int> s;
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        cin >> tmp;
        s.insert(tmp);
    }
    cout << (*(s.begin())) * (*(s.rbegin())); // 진짜 약수중 가장 작은 수와 가장 큰수의 곱
}