#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map <string, int> pokemon_num; // 이름과 번호 같이 저장. 이름이 들어왔을때 활용.
    vector <string> pokemon; // 이름만 저장. 번호가 들어왔을때 활용.
    int n, m;
    string tmp;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        pokemon_num.insert({tmp, i + 1});
        pokemon.push_back(tmp);
    }
    for (int j = 0; j < m; j++)
    {
        cin >> tmp;
        if (tmp[0] < 'A') // 번호가 들어왔을때
        {
            int index = stoi(tmp);
            cout << pokemon[index - 1] << '\n';
        }
        else
        {
            cout << pokemon_num[tmp] << '\n';
        }
    }
}