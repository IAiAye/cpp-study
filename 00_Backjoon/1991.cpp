#include <iostream>
using namespace std;

int n;
struct Node
{
    Node* left;
    Node* right;
    char data;
    int num;
};
Node* arr[26];

void preorder(Node* node)
{
    // 노드가 없을 때
    if (node == nullptr) return;

    cout << node->data;
    preorder(node->left);
    preorder(node->right);
}
void inorder(Node* node)
{
    // 노드가 없을 때
    if (node == nullptr) return;

    inorder(node->left);
    cout << node->data;
    inorder(node->right);
}
void postorder(Node* node)
{
    // 노드가 없을 때
    if (node == nullptr) return;

    postorder(node->left);
    postorder(node->right);
    cout << node->data;
}

void Input()
{
    cin >> n;
    Node* root = new Node();
    root->data = 'A';
    root->num = 1;

    arr[0] = root;

    for (int i = 0; i < n; i++)
    {
        char parent, lchild, rchild;
        cin >> parent >> lchild >> rchild;

        if (lchild != '.')
        {
            Node* left = new Node();

            left->data = lchild;
            left->num = arr[parent - 'A']->num * 2;
            arr[lchild - 'A'] = left;
            arr[parent - 'A']->left = left;
        }
        if (rchild != '.')
        {
            Node* right = new Node();

            right->data = rchild;
            right->num = arr[parent - 'A']->num * 2 + 1;
            arr[rchild - 'A'] = right;
            arr[parent - 'A']->right = right;
        }
    }
}

void Solution()
{    
    preorder(arr[0]);
    cout << '\n';
    inorder(arr[0]);
    cout << '\n';
    postorder(arr[0]);
    cout << '\n';

    for (int i = 0; i < 26; i++)
    {
        if (arr[i] != nullptr) 
            delete arr[i];
    }
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