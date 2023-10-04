#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;

    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    for (int i = 0; i < n; i++)
    {
        if (max_pq.size() > min_pq.size())
            min_pq.push(v[i]);
        else
            max_pq.push(v[i]);
        
        if (!max_pq.empty() && !min_pq.empty())
        {
            if (max_pq.top() > min_pq.top())
            {
                int a = max_pq.top();
                max_pq.pop();
                int b = min_pq.top();
                min_pq.pop();

                max_pq.push(b);
                min_pq.push(a);
            }
        }
        cout << max_pq.top() << '\n';
    }
    
    return 0;
}