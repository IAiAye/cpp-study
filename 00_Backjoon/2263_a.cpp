// 제출번호 63322953 참고

#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> In;
vector<int> Post;

pair<int, int> node[100005];
int in[100005];
int in_idx[100005];
int post[100005];
int post_idx[100005];
int visited[100005];

// root에서 시작, left와 right는 inorder기준
void trace(int k, int left, int right) 
{
    // 왼쪽을 먼저 체크해도록 해준다.
    visited[k] = 1;

    int post_LeftIdx = 0;
    int in_RLength = right - in_idx[k];
    post_LeftIdx = (post_idx[k] - 1) - in_RLength;

    if (visited[post[post_LeftIdx]] == 1 || post_LeftIdx < 0)
        post_LeftIdx = 0;

    // 좌측 노드 기록, 없다면 0
    node[k].first = post[post_LeftIdx];
    if (post_LeftIdx)
        trace(post[post_LeftIdx], left, in_idx[k] - 1);

    int post_RightIdx = 0;
    post_RightIdx = post_idx[k] - 1;
    if (visited[post[post_RightIdx]] == 1 || post_RightIdx < 0)
        post_RightIdx = 0;

    // 우측 노드 기록, 없다면 0
    node[k].second = post[post_RightIdx];
    if (post_RightIdx)
        trace(post[post_RightIdx], in_idx[k] + 1, right);
}

void preorder(int n) 
{
    if (!n)
        return;

    cout << n << ' ';
    preorder(node[n].first);
    preorder(node[n].second);
}

void Input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> in[i];
        in_idx[in[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> post[i];
        post_idx[post[i]] = i;
    }
}

void Solution()
{    
    int root = post[n];
    trace(root, 1, n);
    preorder(root);
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