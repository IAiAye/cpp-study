#include <iostream>
#include <vector>
using namespace std;

int node[10001];

void postorder(int start, int end)
{
    if (start >= end)
        return;
        
    if (start == end - 1)
    {
        cout << node[start] << '\n';
        return;
    }

    int idx = start + 1;
    while (idx < end)
    {
        if (node[start] < node[idx])
            break;
        idx++;
    }
    
    // for (; idx <= end; idx++)
    // {
    //     if (node[start] < node[idx])
    //         break;
    // }
    
    postorder(start + 1, idx);
    postorder(idx, end);
    cout << node[start] << '\n';
}

void Input()
{
    int num;
    int nodeIdx = 0;
    while (cin >> num)
        node[nodeIdx++] = num;

    postorder(0, nodeIdx);
}

void Solution()
{    
}

void Solve()
{
    Input();
    Solution();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve();
    
    return 0;
}