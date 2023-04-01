#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, m;
        int cnt = 0;
        cin >> n >> m;
        vector <int> v; // 우선순위대로 정렬하기 위한 벡터
        queue <int> q;

        for (int j = 0; j < n; j++)
        {
            int tmp;
            cin >> tmp;
            v.push_back(tmp);
            q.push(tmp);
        }
        sort(v.begin(), v.end(), greater<int>()); // 큰수부터 정렬
        while(1)
        {
            if (q.front() == v[cnt])
            {
                cnt++;
                if (m == 0) break; // 목표 문서가 제일 앞에 있을때 탈출
                q.pop();
            }
            else
            {
                q.push(q.front());
                q.pop();
            }
            m--;
            if (m == -1) m += q.size();
        }
        cout << cnt << '\n';
    }
}