#include <iostream>
#include <algorithm>
using namespace std;

int coin[10];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;
    int cnt = 0;
    int idx = 0;
    bool flag = true;

    for (int i = 0; i < N; i++)
    {
        cin >> coin[i];
        if (coin[i] > K && flag)
        {
            idx = i - 1;
            flag = false;
        }
    }
    if (flag) // 만약 최대 크기가 K보다 작다면.
    {
        idx = N - 1;
    }
    
    int tmp;
    while(1)
    {
        tmp = K / coin[idx];
        if (!tmp) // 몫이 0일때.
        {
            idx--;
            continue;
        }
        else
        {
            K -= tmp * coin[idx];
            cnt += tmp;
            if (K == 0)
            {
                break;
            }
            idx--;
        }
    }
    cout << cnt << '\n';

    return 0;
}
