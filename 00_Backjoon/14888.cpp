#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n;
int arr[11] = {0};
vector <char> operator_char; // 연산자 저장
set <int> s; // 답 저장
bool visited[10] = {0};

int operation(int i, int ans, int cnt)
{
    if (operator_char[i] == '+')
    {
        ans += arr[cnt + 1];
        return ans;
    }
    if (operator_char[i] == '-')
    {
        ans -= arr[cnt + 1];
        return ans;
    }
    if (operator_char[i] == '*')
    {
        ans *= arr[cnt + 1];
        return ans;
    }
    if (operator_char[i] == '/')
    {
        ans /= arr[cnt + 1];
        return ans;
    }
    return 0;
}

void dfs(int cnt, int ans)
{
    if (cnt == n - 1)
    {
        s.insert(ans);
        return;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            int tmp = ans;
            ans = operation(i, ans, cnt);
            dfs(cnt + 1, ans);
            ans = tmp;
            visited[i] = false;
        }
    }
}


int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    char tmp_char;
    int tmp;
    for (int j = 0; j < 4; j++)
    {
        if (j == 0) tmp_char = '+'; 
        if (j == 1) tmp_char = '-'; 
        if (j == 2) tmp_char = '*'; 
        if (j == 3) tmp_char = '/'; 
        cin >> tmp;
        for (int k = 0; k < tmp; k++)
        {
            operator_char.push_back(tmp_char);
        }
    }
    dfs(0, arr[0]);
    cout << *s.rbegin() << '\n' << *s.begin() << '\n';
}