#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
bool number[10];
bool visited[1000001];
vector<int> numbers;
vector<int> unbroken;
bool digit[7];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

void Calculate(int digit)
{
    vector<int> temp;
    for (int i = 0; i < static_cast<int>(numbers.size()); i++)
    {
        if (numbers[i] == 0 && digit != 1)
            continue;
            
        for (int j = 0; j < static_cast<int>(unbroken.size()); j++)
        {
            temp.push_back(numbers[i] * 10 + unbroken[j]);
        }   
    }
    numbers.swap(temp);
    for (int i = 0; i < static_cast<int>(numbers.size()); i++)
    {
        if (!visited[numbers[i]])
        {
            pq.push({digit, numbers[i]});
            visited[numbers[i]] = true;
        }
        
    }
}

void Input()
{
    cin >> n;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int broken;
        cin >> broken;
        number[broken] = true;
    }
    for (int i = 0; i < 10; i++)
    {
        if (!number[i])
        {
            unbroken.push_back(i);
        }
    }
    numbers.push_back(0);
}

void Solution()
{
    digit[0] = true;
    pq.push({0, 100});

    while(!pq.empty())
    {
        int cnt = pq.top().first;
        int channel = pq.top().second;
        //visited[channel] = true;

        pq.pop();
        if (channel == n)
        {
            cout << cnt << '\n';
            break;
        }

        if (cnt <= 6 && !digit[cnt])
        {
            Calculate(cnt);
            digit[cnt] = true;
        }
        
        if (channel - 1 >= 0 && !visited[channel - 1])
        {
            pq.push({cnt + 1, channel - 1});
            visited[channel - 1] = true;
        }
            
        if (!visited[channel + 1])
        {
            pq.push({cnt + 1, channel + 1});
            visited[channel + 1] = true;
        }
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