#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
static bool comp(pair <string, int> &a, pair <string, int> &b) 
{ 
    if (a.second == b.second)
    {
        if (a.first.length() == b.first.length())
        {
            return a.first < b.first;
        } else return a.first.length() > b.first.length();
    } else return a.second > b.second; 
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    string tmp;
    map <string, int> dict; // 중복을 제거하고 갯수 카운트.
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (tmp.length() >= m) // 글자개수보다 작으면 패스.
        {
            if (dict.count(tmp)) dict[tmp]++;
            else dict[tmp] = 1;
        }
    }
    vector <pair <string, int>> vec_dict(dict.begin(), dict.end()); // 벡터로 복사해주기.
    sort(vec_dict.begin(), vec_dict.end(), comp);
    for (int i = 0; i < vec_dict.size(); i++)
    {
        cout << vec_dict[i].first << '\n';
    }
}