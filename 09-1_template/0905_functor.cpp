#include <iostream>

// 템플릿을 명시해주고 아래에 템플릿으로 만들고 싶은 것을 기입
template <typename T>
class Vector
{
    T* data;
    int capacity;
    int length;

public:

    typedef T value_type;

    // 생성자
    Vector(int n = 1) : data(new T[n]), capacity(n), length(0) {}

    // 맨 뒤에 원소 추가
    void push_back(T s)
    {
        // 용량이 길이보다 작거나 같을때 늘려줘야 한다.
        if (capacity <= length)
        {
            T* temp = new T[capacity * 2];
            for (int i = 0; i < length; i++)
            {
                temp[i] = data[i];
            }
            
            delete[] data;
            data = temp;
            capacity *= 2;
        }
        
        data[length] = s;
        length++;
    }

    // 임의의 원소 위치에 접근
    T operator[](int i) { return data[i]; }

    // x번째 위치한 원소 제거
    void remove(int x)
    {
        for (int i = x + 1; i < length; i++)
        {
            // 한칸씩 앞으로 당기기
            data[i - 1] = data[i];
        }
        length--;
    }

    // 현재 벡터의 크기
    int size() { return length; }

    void swap(int i, int j)
    {
        T temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }

    ~Vector()
    {
        if (data)
        {
            delete[] data;
        }
    }
};

template <typename Cont>
void bubble_sort(Cont& cont)
{
    for (int i = 0; i < cont.size(); i++)
    {
        for (int j = i + 1; j < cont.size(); j++)
        {
            if (cont[i] > cont[j])
            {
                cont.swap(i, j);
            }
        }
    }
}

template <typename Cont, typename Comp>
void bubble_sort(Cont& cont, Comp& comp)
{
    for (int i = 0; i < cont.size(); i++)
    {
        for (int j = i + 1; j < cont.size(); j++)
        {
            if (!comp(cont[i], cont[j]))
            {
                cont.swap(i, j);
            }
        }
    }
}

// 이 클래스는 위 버블 소트에서 마치 함수처럼 사용된다.
// 이처럼 함수인척을 하는 객체를 함수 객체, Functor라고 부른다.
struct Comp1
{
    bool operator()(int a, int b) { return a > b; }
};
struct Comp2
{
    bool operator()(int a, int b) { return a < b; }
};

int main()
{
    Vector<int> int_vec;
    int_vec.push_back(3);
    int_vec.push_back(1);
    int_vec.push_back(2);
    int_vec.push_back(8);
    int_vec.push_back(5);
    int_vec.push_back(3);

    std::cout << "정렬 이전 ---- " << std::endl;
    for (int i = 0; i < int_vec.size(); i++)
    {
        std::cout << int_vec[i] << ' ';
    }
    std::cout << std::endl;

    Comp1 comp1;
    bubble_sort(int_vec, comp1);

    std::cout << std::endl << "내림차순 정렬 이후 ---- " << std::endl;
    for (int i = 0; i < int_vec.size(); i++)
    {
        std::cout << int_vec[i] << ' ';
    }
    std::cout << std::endl;

    Comp2 comp2;
    bubble_sort(int_vec, comp2);

    std::cout << std::endl << "오름차순 정렬 이후 ---- " << std::endl;
    for (int i = 0; i < int_vec.size(); i++)
    {
        std::cout << int_vec[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}