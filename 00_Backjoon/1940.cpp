#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int startPoint = 0;
int endPoint;
int N, M;
int cnt;

vector <int> materials;
int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> N >> M;

    // 마지막 지점에서 시작, 앞뒤에서 조여오기
    endPoint = N - 1;

    for (int i = 0; i < N; i++)
    {
        int material;
        std::cin >> material;
        materials.push_back(material);
    }
    
    sort(materials.begin(), materials.end());

    // 한 포인트에서 만날 때까지
    while (startPoint != endPoint)
    {
        int sum = materials[startPoint] + materials[endPoint];

        if (sum == M)
        {
            cnt++;
            endPoint--;
        }
        else if (sum > M) endPoint--;
        else startPoint++;
    }
    std::cout << cnt;
    return 0;
}