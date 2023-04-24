#include <iostream>
#include <cstdlib>
using namespace std;

int heap_abs[100001];
int heap_size = 0;

// a가 절대값이 작거나, 같다면 음수일때 참
bool aIsSmall(int a, int b)
{
    if (abs(a) < abs(b)) return true;
    else if ((a == (-1) * b) && (a < b)) return true;
    return false;    
}

void insert_heap(int num)
{
    heap_size++;
    int i = heap_size;
    // num이 더 작을때 반복.
    while ((i != 1) && !aIsSmall(heap_abs[i / 2], num))
    {
        // 부모 노드와 비교했을때, 부모가 더 크다면 자식노드로 내린다.
        heap_abs[i] = heap_abs[i / 2];
        i /= 2;
    }
    heap_abs[i] = num;
}

void delete_heap()
{
    // 1번 노드 출력
    cout << heap_abs[1] << '\n';
    // 마지막 노드 저장
    int temp = heap_abs[heap_size];
    heap_size--;

    int parent = 1;
    int child = parent * 2;

    while (child <= heap_size)
    {
        // 자식 노드 중 더 작은 노드 찾기
        if ((child < heap_size) && !aIsSmall(heap_abs[child], heap_abs[child + 1])) child++;
        // 자식 노드보다 부모 노드가 작다면 탈출
        if (!aIsSmall(heap_abs[child], temp)) break;
        heap_abs[parent] = heap_abs[child];
        parent = child;
        child *= 2;
    }
    // 재구성한 위치에 삽입
    heap_abs[parent] = temp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        if (num)
        {
            insert_heap(num);
        }
        else if (heap_size == 0)
        {
            cout << 0 << '\n';
        }
        else
        {
            delete_heap();
        }
    }
    
    return 0;
}
