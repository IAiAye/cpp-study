#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

vector <pair <unsigned int, unsigned int>> times;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    pair <unsigned int, unsigned int> time;
    for (int i = 0; i < N; i++)
    {
        cin >> time.second >> time.first;
        times.push_back(time);
    }
    sort(times.begin(), times.end());

    int cnt = 0;
    unsigned int fin_time = 0;
    for (int i = 0; i < N; i++)
    {
        if (times[i].second >= fin_time)
        {
            cnt++;
            fin_time = times[i].first;
        }
    }
    cout << cnt << '\n';
    

    return 0;
}
