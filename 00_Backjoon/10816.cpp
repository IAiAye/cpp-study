#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    int tmp;
    cin >> n;
    vector <int> card;
    map <int, int> card_cnt;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        card.push_back(tmp);
        if (card_cnt.find(tmp) != card_cnt.end())
        {
            card_cnt[tmp]++;
        } else card_cnt.insert({tmp, 1}); // 카드의 개수를 세준다.
    }
    sort(card.begin(), card.end());

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        if (binary_search(card.begin(), card.end(), tmp))
        {
            cout << card_cnt[tmp] << ' ';
        } else cout << "0 ";
    }
}