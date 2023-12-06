#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
using namespace std;
using ll = long long;

ll crossProduct(pair <ll, ll>& o, pair <ll, ll>& a, pair <ll, ll>& b)
{
    ll x1 = a.first - o.first;
    ll y1 = a.second - o.second;

    ll x2 = b.first - o.first;
    ll y2 = b.second - o.second;
    
    ll ans = (x1 * y2 - x2 * y1);
    if (ans > 0)
        return 1;
    else if (ans == 0)
        return 0;
    else
        return -1;
}

bool checkParallel(pair <ll, ll>& p1, pair <ll, ll>& p2, pair <ll, ll>& p3, pair <ll, ll>& p4)
{
    int p1p2 = crossProduct(p1, p2, p3) * crossProduct(p1, p2, p4); // l1 기준
    int p3p4 = crossProduct(p3, p4, p1) * crossProduct(p3, p4, p2); // l2 기준

    // 두 직선이 일직선 상에 존재
    if (p1p2 == 0 && p3p4 == 0)
    {
    	// 비교를 일반화하기 위한 점 위치 변경
        if (p1 > p2) swap(p2, p1);
        if (p3 > p4) swap(p3, p4);
        
        return p3 <= p2 && p1 <= p4; // 두 선분이 포개어져 있는지 확인
    }
    
    return p1p2 <= 0 && p3p4 <= 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    pair <ll, ll> p1;
    pair <ll, ll> p2;
    pair <ll, ll> p3;
    pair <ll, ll> p4;

    cin >> p1.first >> p1.second >> p2.first >> p2.second;
    cin >> p3.first >> p3.second >> p4.first >> p4.second;

    if (checkParallel(p1, p2, p3, p4))
        cout << 1 << '\n';
    else
        cout << 0 << '\n';
    
    return 0;
}