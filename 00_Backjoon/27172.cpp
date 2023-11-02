#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <stack>
using namespace std;

int n;
int num[100000];
int score[1000001];
bool isCard[1000001];

void Input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        isCard[num[i]] = true;
    }
    
}

void Solution()
{
    for (int i = 0; i < n; i++)
    {
        int card = num[i];

        for (int j = card * 2; j < 1000001; j += card)
        {
            if (isCard[j])
            {
                score[card]++;
                score[j]--;
            }
        }
    }
    


    for (int i = 0; i < n; i++)
    {
        cout << score[num[i]] << ' ';
    }
    
    cout << '\n';
    
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