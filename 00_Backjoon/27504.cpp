#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
using namespace std;
using ll = long long;

#define MAX 360000
string n,m;
int result = 0;
vector<int> result_vec;


vector<int> makeTable(vector<int>& pattern)
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

bool kmp(vector<int>& parent, vector<int>& pattern)
{
    vector<int> table = makeTable(pattern);
    int parentSize = parent.size();
    int patternSize = pattern.size();
    int j = 0;

    for(int i = 0 ; i < parentSize; i++)
    {
        if (j > 0 && parent[i] != pattern[j])
        {
            while(j > 0 && parent[i] != pattern[j])
            {
                //패턴이랑 parent랑 다를 동안에.
                //j 복귀 패턴.
                j = table[j - 1];
            }
        }
        
        //같을 때.
        if(parent[i] == pattern[j])
        {
            //온전하게 패턴 찾았을 때.
            if(j == patternSize - 1)
            {
                return true;
            }
            else
            {
                //단순 매칭.
                j++; 
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> melody(n);
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        vector<int> tmp1(k);
        vector<int> tmp2(k - 1);
        for (int j = 0; j < k; j++)
        {
            cin >> tmp1[j];
            if (j != 0)
                tmp2[j - 1] = tmp1[j] - tmp1[j - 1];
        }
        melody[i] = tmp2;
    }
    
    int l;
    cin >> l;
    vector<int> pattern1(l);
    vector<int> pattern(l - 1);
    for (int i = 0; i < l; i++)
    {
        cin >> pattern1[i];
        if (i != 0)
            pattern[i - 1] = pattern1[i] - pattern1[i - 1];
    }
    
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (kmp(melody[i], pattern))
            ans.push_back(i + 1);
    }
    if (ans.empty())
        cout << -1 << '\n';
    else
    {
        for (int i : ans)
            cout << i << ' ';
        cout << '\n';
    }
    
    return 0;
}