#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

vector<int> init(int& n, int& S)
{
    // vector<int> tree;

    while(S < n)
        S <<= 1;
    vector<int> tree(S * 2, 0);

    // int SS = S;
    // while (SS >>= 1)
    // {
    //     for (int i = 0; i < SS; i++)
    //     {
    //         int j = SS + i;
    //         tree[j] = tree[j * 2] + tree[j * 2 + 1];
    //     }
    // }
    return tree;
}

int query(int num, int S, vector<int>& tree)
{
    int totalNum = num;
    int idx = 1;
    while (idx < S)
    {
        int leftNum = tree[idx * 2];
        int rightNum = tree[idx * 2 + 1];
        if (totalNum <= leftNum)
            idx = idx * 2;
        else
        {
            idx = idx * 2 + 1;
            totalNum -= leftNum;
        }
    }
    return idx - S;
}

void update(int idx, int val, int S, vector<int>& tree)
{
    idx += S;
    tree[idx] += val;
    while (idx >>= 1)
        tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N = 1000000; 
    int Q;
    int S = 1;

    cin >> Q;

    vector<int> tree = init(N, S);

    while (Q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int a;
            cin >> a;
            int index = query(a, S, tree);
            cout << index + 1 << '\n';
            update(index, -1, S, tree);
        }
        else
        {
            int a, b;
            cin >> a >> b;
            update(a - 1, b, S, tree);
        }
    }

    return 0;
}