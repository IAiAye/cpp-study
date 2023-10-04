#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <string.h>
using namespace std;
using ll = long long;

string text;
int table[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    cin >> text;
    while(text[0] != '.')
    {
        int sz = text.size();
        memset(table, 0, sizeof(table));
        int j = 0;

        for(int i = 1; i < text.size(); i++)
        {
            while(j > 0 && text[i] != text[j]) 
                j = table[j-1];
            if(text[i] == text[j]) 
                table[i] = ++j;
        }
        
        int div = sz - table[sz - 1];
        if(sz % div) 
            cout << 1 << "\n";
        else 
            cout << sz / div << "\n";
        
        cin >> text;
    }

    return 0;
}