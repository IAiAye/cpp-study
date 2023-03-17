#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    int tmp;
    cin >> n;
    vector <int> card;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        card.push_back(tmp);
    }
    sort(card.begin(), card.end());

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        cout << binary_search(card.begin(), card.end(), tmp) << ' '; // O(log N)의 시간 복잡도
    }
}