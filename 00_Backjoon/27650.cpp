#include <iostream>
#include <vector>
#include <unordered_set>

#define MAX 5000001
bool isPrime[MAX];

int main() 
{
    int N;
    std::cin >> N;

    for (int i = 2; i <= N; i++)
        isPrime[i] = true;
    
    for (int i = 2; i <= N; i++)
    {
        if (isPrime[i])
        {
            int j = 2;
            while (i * j <= N)
            {
                isPrime[i * j] = false;
                j++;
            }
        }
    }

    // 소수들의 목록을 Vector로 변환하여 오름차순으로 정렬합니다.
    std::vector<int> primeList;
    for (int i = 2; i <= N; i++)
    {
        if (isPrime[i])
            primeList.push_back(i);
    }
    
    int T = N; // 정답을 저장
    int Q = 20; // 남은 질문 횟수

    // 이분탐색을 사용하여 마법박스에 들어있지 않은 수들 중 최솟값을 찾습니다.
    int start = 0;
    int end = primeList.size() - 1;
    while (--Q >= 0) 
    {
        int mid = (start + end) / 2;
        int i = primeList[mid]; // Vector 중앙에 위치한 소수를 가져옵니다.

        // i 이하의 2 이상의 양의 정수가 마법박스에 모두 들어있는지 질문합니다.
        std::cout << "? " << i << std::endl;
        std::cout.flush();

        // 답변을 받습니다.
        int result;
        std::cin >> result;

        // 만약 더 이상 이분탐색을 수행할 수 없다면 질문을 종료합니다.
        if (start == end) 
        {
            if (result == 0)
                T = i; // 마지막 질문에 대한 답변이 0이었다면 정답은 i
            break;
        }

        // 답변에 따라 start 또는 end를 조정합니다.
        else {
            if (result == 1) 
            {
                // 2 이상, mid 이하의 양의 정수가 마법박스에 모두 들어 있다
                // mid 왼쪽으로는 더 이상 볼 일이 없다
                start = mid + 1;
            } else 
            {
                // 그렇지 않다
                // mid 왼쪽만 보면 된다
                end = mid - 1;
                T = i; // 우선 i를 정답으로 저장 해놓는다.
            }
        }
    }

    // 정답을 출력합니다.
    std::cout << "! " << T << std::endl;
    std::cout.flush();

    return 0;
}
