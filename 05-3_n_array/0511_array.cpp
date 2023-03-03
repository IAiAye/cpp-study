class Array
{
private:
    const int dim; // 몇차원인지에 대한 정보.
    int* size; // size[0] * size[1] * size[2] * ..... * size[dim - 1] 짜리 배열이다.

    struct Address
    {
        int level;
        // 맨 마지막 레벨(dim - 1 레벨) 은 데이터 배열을 가르키고,
        // 그위 상위 레벨에서는 다음 address 배열을 가르킨다.
        void* next;
    };

    Address* top;

public:
    Array(int dim, int* array_size) : dim(dim)
    {
        size = new int[dim];
        for (int i = 0; i < dim; i++)
        {
            size[i] = array_size[i];
        }
    }

    void initialize_address(Address *current)
    {
        if (!current) return; // NULL 일때 처리해줌.
        if (current->level == dim - 1) // 재귀함수의 종료 조건.
        {
            current->next = new int[size[current->level]]; // 트리 마지막 부분에서 int 형을 저장하는 포인터 배열 생성.
            return;
        }
        current->next = new Address[size[current->level]]; // current 의 next 부분에 새로운 시작 주소값을 만들어준다.
        for (int i = 0; i < size[current->level]; i++)
        { // 다음 단계로 넘어가는 과정.
            (static_cast<Address *>(current->next) + 1)->level = current->level + 1;

            initialize_address(static_cast<Address *>(current->next) + 1);
        }
    }
};

