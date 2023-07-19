#include <iostream>
using namespace std;

int n;
int Times[1001];

void Input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> Times[i];
    }
}

void Solution()
{
    int i, j;
    for (int i = 2; i <= n; i++)
    {
        int key = Times[i];

        // 이미 정렬된 부분에서 뒤에서부터 조사하면서 key보다 큰 값들을 밀어준다.
        for (j = i - 1; j >= 0 && Times[j] > key; j--)
        {
            Times[j + 1] = Times[j];
        }
        Times[j + 1] = key;
    }
    
    int sum = 0;
    int psum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += Times[i];
        psum += sum;
    }
    cout << psum << '\n';
}

void Solve()
{
    Input();
    Solution();
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    Solve();

    return 0;
}