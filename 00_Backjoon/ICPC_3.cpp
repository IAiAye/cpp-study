#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;
using ll = long long;

#define MAX 200001


struct node
{
    vector<node*> child;
    int index = 0;
    int value = -1;

    node(int index) : index(index) {}
};

int n, r, l;
unordered_map<int, node*> m;

int dfs(node* nod, node* parent, int level)
{
    vector<node*> ch = nod->child;
    if (ch.size() == 1 && ch[0] == parent)
        return nod->value;

    int val;
    // 홀수 레벨, min
    if (level & 1)
    {
        val = 1e9 + 1;
        for (auto c : ch)
        {
            if (c == parent)
                continue;
            val = min(val, dfs(c, nod, level + 1));
        }
    }
    else
    {
        val = -1;
        for (auto c : ch)
        {
            if (c == parent)
                continue;
            val = max(val, dfs(c, nod, level + 1));
        }
    }
    nod->value = val;

    // cout << nod->index << ' ' << nod->value << '\n';

    return val;
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    cin >> n >> r;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        node* nodeU;
        node* nodeV;
        if (m.find(u) == m.end())
        {
            nodeU = new node(u);
            m[u] = nodeU;
        }
        else
            nodeU = m[u];
        
        if (m.find(v) == m.end())
        {
            nodeV = new node(v);
            m[v] = nodeV;    
        }
        else
            nodeV = m[v];
        
        nodeU->child.push_back(nodeV);
        nodeV->child.push_back(nodeU);
    }

    cin >> l;
    for (int i = 0; i < l; i++)
    {
        int k, t;
        cin >> k >> t;
        node* nod = m[k];
        nod->value = t;
    }

    dfs(m[r], nullptr, 0);

    int q;
    cin >> q;
    while (q--)
    {
        int qi;
        cin >> qi;
        cout << m[qi]->value << '\n';
    }
    
    
    return 0;
}