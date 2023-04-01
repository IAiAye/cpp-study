#include <iostream>
#include <deque>
using namespace std;

int main()
{
    int n, m;
    int cnt = 0;
    cin >> n >> m;
    deque <int> d;
    for (int i = 0; i < n; i++)
    {
        d.push_back(i + 1);
    }
    for (int j = 0; j < m; j++)
    {
        int tmp;
        int left, right;
        cin >> tmp;

        for (int i = 0; i < d.size(); i++)
        {
            if (d[i] == tmp)
            {
                left = i; // 왼쪽으로 옮겨야하는 횟수
                right = d.size() - i; // 오른쪽으로 옮겨야하는 횟수
                break;
            }
        }
        if (left < right)
        {
            cnt += left;
            for (int k = 0; k < left; k++)
            {
                d.push_back(d.front());
                d.pop_front();
            }
            d.pop_front();
        }
        else
        {
            cnt += right;
            for (int k = 0; k < right; k++)
            {
                d.push_front(d.back());
                d.pop_back();
            }
            d.pop_front();
        }
    }
    cout << cnt;
}
