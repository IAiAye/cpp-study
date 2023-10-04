#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

struct input
{
    int left, right, x;
};

struct pqelem
{
    int left, right, len;
};

struct compare
{
    bool operator () (pqelem a, pqelem b)
    {
        return a.len > b.len;
    }
};


input in[100002];
int n, k, ans = 0;
int length[100002];
priority_queue<pqelem, vector<pqelem>, compare> pq;

void Input()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> in[i].x;
        in[i].left = i - 1;
        in[i].right = i + 1;
    }
}

void Solution()
{
    for (int i = 1; i < n; i++)
    {
        pqelem tmp;
        tmp.left = i;
        tmp.right = i + 1;
        tmp.len = in[i + 1].x - in[i].x;
        pq.push(tmp);
        length[i] = tmp.len;
    }
    while (k--)
    {
        pqelem tmp = pq.top();
        pq.pop();

        int left = tmp.left;
        int right = tmp.right;
        int len = tmp.len;

        if (left < 1 || right > n || right != in[left].right || left != in[right].left)
        {
            k++;
            continue;
        }
        
        ans += len;
        int nextLeft = in[left].left;
        int nextRight = in[right].right;

        tmp.left = nextLeft;
        tmp.right = nextRight;
        
        length[nextLeft] = length[nextLeft] + length[right] - len;
        tmp.len = length[nextLeft];
        pq.push(tmp);

        in[nextLeft].right = nextRight;
        in[nextRight].left = nextLeft;
    }
    cout << ans << '\n';
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