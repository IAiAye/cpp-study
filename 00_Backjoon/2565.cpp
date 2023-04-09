#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool comp(pair <int, int> &a, pair <int, int> &b)
{
    if (a.first < b.first) return true;
    else return false;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    vector <pair <int, int>> rope;
    for (int i = 0; i < n; i++)
    {
        pair <int, int> tmp;
        cin >> tmp.first >> tmp.second;
        rope.push_back(tmp);
    }
    sort(rope.begin(), rope.end(), comp); // A를 기준으로 정렬.

    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int num = rope[i].second;
        
        if (arr.empty() || arr.back() < num)
        // 벡터의 마지막 수보다 클때만 추가.
        {
            arr.push_back(num);
        }
        else
        {
            auto it = lower_bound(arr.begin(), arr.end(), num);
            // 그 수보다 큰 첫번째 반복자 반환.
            *it = num;
            // 그 수를 num으로 치환해준다.
        }
    }
    
    cout << n - arr.size() << '\n';
    
    return 0;
}