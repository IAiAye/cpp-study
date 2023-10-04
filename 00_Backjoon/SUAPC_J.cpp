#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
using namespace std;
using ll = unsigned long long;

ll n;
vector<string> num;

bool cmp(string& a, string& b)
{
    if (a[0] == b[0])
    {
        int len1 = a.size();
        int len2 = b.size();

        
    }
    

    return a[0] > b[0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    cin >> n;
    ll m = 1;
    string num1 = "";
    while (m * 2 < n)
    {
        m *= 2;
        num1 += "2";
    }
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            num.push_back(to_string(i));
            n /= i;
        }
    }

    sort(num.begin(), num.end(), cmp);

    if (n > 1)
        num.push_back(n);

    string num2 = "";
    int Size = num.size();
    for (int i = Size - 1; i >= 0; i--)
    {
        num2 += num[i];
    }

    int carry = 0; // 자릿수 올림을 나타내는 변수
    string result = ""; // 결과를 저장할 문자열

    int i = num1.length() - 1;
    int j = num2.length() - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int digit1 = i >= 0 ? num1[i] - '0' : 0;
        int digit2 = j >= 0 ? num2[j] - '0' : 0;
        
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        int digit = sum % 10;
        
        result = to_string(digit) + result;
        
        i--;
        j--;
    }

    cout << result << '\n';

    return 0;
}