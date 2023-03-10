#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool compare(pair <int, string> a, pair <int, string> b)
{
    return a.first < b.first;
}
int main()
{
    int num;
    pair <int, string> temp;
    vector<pair<int, string>> boj_list;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> temp.first >> temp.second;
        boj_list.push_back(temp);
    }
    stable_sort(boj_list.begin(), boj_list.end(),compare); // sort로 진행할경우 뒤에 순서가 유지되는 것을 보장해주지 않는다. random.
    for (int i = 0; i < num; i++)
    {
        cout << boj_list[i].first << ' ' << boj_list[i].second << '\n';
    }
}