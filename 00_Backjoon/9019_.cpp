#include <iostream>
#include <queue>
using namespace std;

int t;
int a, b;

int beforeNum;
int currentNum;
char operChar;

// 방문했는지 여부를 체크하고, 체크가 안되었다면 before[i] = j 일때 j -> i 순으로 이동함을 나타낸다.
int before[10000];
// 이동할때의 연산자를 저장
char oper[10000];
// 정답 연산자를 역순으로 저장
char ans[10000];

queue <int> q;

void fD(int num)
{
    int nextNum = (num * 2) % 10000;

    if (before[nextNum] != -1) return;
    oper[nextNum] = 'D'; 
    before[nextNum] = num;
    q.push(nextNum);
}
void fS(int num)
{
    int nextNum = num - 1;
    if (nextNum < 0) nextNum = 9999;

    if (before[nextNum] != -1) return;
    oper[nextNum] = 'S'; 
    before[nextNum] = num;
    q.push(nextNum);
}
void fL(int num)
{
    int nextNum = (num % 1000) * 10 + (num / 1000);

    if (before[nextNum] != -1) return;
    oper[nextNum] = 'L'; 
    before[nextNum] = num;
    q.push(nextNum);
}
void fR(int num)
{
    int nextNum = (num % 10) * 1000 + (num / 10);

    if (before[nextNum] != -1) return;
    oper[nextNum] = 'R'; 
    before[nextNum] = num;
    q.push(nextNum);
}

void bfs()
{
    q.push(a);
    while (!q.empty())
    {
        int num = q.front();
        if (num == b)
        {
            while (q.empty() == 0)
                q.pop();
            break;
        }
        fD(num);
        fS(num);
        fL(num);
        fR(num);
        q.pop();
    }
}

void printAns()
{
    currentNum = b;
    beforeNum = before[currentNum];

    int idx;
    // 처음값으로 돌아올 때까지 ans에 연산자를 추가하면서 반복
    for (idx = 1; currentNum != a; idx++)
    {
        ans[idx] = oper[currentNum];
        currentNum = beforeNum;
        beforeNum = before[currentNum];
    }

    for (;idx > 0; idx--)
    {
        // 역순으로 저장되었으므로 역순으로 인덱스를 찾으면서 출력
        operChar = ans[idx];
        if (operChar == 'D')
            cout << "D";
        else if (operChar == 'S')
            cout << "S";
        else if (operChar == 'L')
            cout << "L";
        else if (operChar == 'R')
            cout << "R";
    }
    cout << '\n';
}

void Input()
{
    cin >> t;
}

void Solution()
{
    while (t--)
    {
        for (int k = 0; k < 10000; k++)
        {
            before[k] = -1;
            ans[k] = 0;
        }

        cin >> a >> b;
        
        bfs();
        printAns();
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