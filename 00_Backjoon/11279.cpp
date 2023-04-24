#include <iostream>
using namespace std;

int heap_max[100001];
int heap_size = 0;

void insert_heap(int num)
{
    heap_size++;
    int i = heap_size;
    while ((i != 1) && (heap_max[i / 2] < num))
    {
        // 부모 노드와 비교했을때, 더 작다면 자식노드로 내린다.
        heap_max[i] = heap_max[i / 2];
        i /= 2;
    }
    heap_max[i] = num;
}

void delete_heap()
{
    // 1번 노드 출력
    cout << heap_max[1] << '\n';
    // 마지막 노드 저장
    int temp = heap_max[heap_size];
    heap_size--;

    int parent = 1;
    int child = parent * 2;

    while (child <= heap_size)
    {
        // 자식 노드 중 더 큰 노드 찾기
        if ((child < heap_size) && (heap_max[child] < heap_max[child + 1])) child++;
        // 자식 노드보다 부모 노드가 크다면 탈출
        if (heap_max[child] <= temp) break;
        heap_max[parent] = heap_max[child];
        parent = child;
        child *= 2;
    }
    // 재구성한 위치에 삽입
    heap_max[parent] = temp;
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
