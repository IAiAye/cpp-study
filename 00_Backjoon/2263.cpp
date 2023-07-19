#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> In;
vector<int> Post;

int in[100005];
int in_idx[100005];
int post[100005];
int post_idx[100005];
int visited[100005];

struct Node
{
    Node* left = nullptr;
    Node* right = nullptr;
    int data;
};

void findTree(Node* node, int inLeft, int inRight)
{
    if (inLeft >= inRight)
        return;

    
    int rootData = node->data;
    int in_rootIdx = in_idx[rootData];

    visited[rootData] = 1;

    // 중위 순회에서 루트 기준으로 양쪽 길이 확인
    int in_RLength = inRight - in_rootIdx;

    // 후위 순회에서 왼쪽, 오른쪽 부분의 마지막 부분 인덱스
    int post_RightIdx = post_idx[rootData] - 1;
    int post_LeftIdx = post_RightIdx - in_RLength;

    // 중위 순회에서 왼쪽이 존재하지 않음.
    if (post_LeftIdx >= 0 && !visited[post[post_LeftIdx]])
    {
        Node* left = new Node();
        left->data = Post[post_LeftIdx];
        node->left = left;

        findTree(left, inLeft, in_rootIdx - 1);
    }
    if (post_RightIdx >= 0 && !visited[post[post_RightIdx]])
    {
        Node* right = new Node();
        right->data = Post[post_RightIdx];

        node->right = right;
        findTree(right, in_rootIdx + 1, inRight);
    }
}

void preorder(Node* node)
{
    // 노드가 없을 때
    if (node == nullptr) 
        return;

    cout << node->data << ' ';
    preorder(node->left);
    preorder(node->right);
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
    Node* root = new Node();
    root->data = post[n];
    findTree(root, 1, n);
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