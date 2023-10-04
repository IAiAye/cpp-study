#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
using namespace std;
using ll = long long;

string n,m;
int result = 0;
vector<int> result_vec;

vector<int> makeTable(string pattern)
{
    int patternSize = (int)pattern.size();
    vector<int> table(patternSize, 0);

    int j = 0;
    for (int i = 1; i < patternSize; i++)
    {
        while (j > 0 && pattern[i] != pattern[j])
        {
            j = table[j - 1];
        }
        if (pattern[i] == pattern[j])
        {
            table[i] = ++j;
        }
    }
    return table;
}

void kmp(string parent, string pattern)
{
    vector<int> table = makeTable(pattern);
    int parentSize = parent.size();
    int patternSize = pattern.size();
    int j = 0;
    for(int i = 0 ; i< parentSize; i++)
    {
        while(j > 0 && parent[i] != pattern[j])
        {
            //패턴이랑 parent랑 다를 동안에.
            //j 복귀 패턴.
            j = table[j - 1];
        }
        //같을 때.
        if(parent[i] == pattern[j])
        {
            //온전하게 패턴 찾았을 때.
            if(j == patternSize - 1)
            {
                result_vec.push_back(i - patternSize + 2); //어느위치에서 찾았는지 
                j = table[j]; // 패턴 째로 스킵.
                result ++; // 몇개 찾았는지.
            }
            else
            {
                //단순 매칭.
                j++; 
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n;
    string str;
    cin >> n >> str;
    auto table = makeTable(str);
    cout << n - table[n - 1] << '\n';

    return 0;
}