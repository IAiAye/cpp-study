// 템플릿 첫 활용
#include <iostream>
#include <string>

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

    ~Vector()
    {
        if (data)
        {
            delete[] data;
        }
    }
};

// 템플릿 특수화
// 예를 들어 bool 자료형을 저장하고 싶다면 1 비트만 있으면 되지만 C++에서 기본으로 처리하는 단위가 1 바이트 이기때문에
// 메모리 낭비를 방지하기 위해 따로 처리를 해보자.
template <>
class Vector<bool>
{
    unsigned int* data;
    int capacity;
    int length;

public:

    typedef bool value_type;

    // 생성자
    Vector(int n = 1) : data(new unsigned int[n / 32 + 1]), capacity(n / 32 + 1), length(0) 
    {
        for (int i = 0; i < capacity; i++)
        {
            data[i] = 0;
        }
    }

    // 맨 뒤에 원소 추가
    void push_back(bool s)
    {
        // 용량이 길이보다 작거나 같을때 늘려줘야 한다.
        if (capacity * 32 <= length)
        {
            unsigned int* temp = new unsigned int[capacity * 2];
            for (int i = 0; i < length; i++)
            {
                temp[i] = data[i];
            }
            
            delete[] data;
            data = temp;
            capacity *= 2;
        }
        
        if (s)
        {
            // length가 8이라면, 32비트 중에서 8번째의 비트를 1로 설정.
            // |= 는 비트 OR연산자
            data[length / 32] |= (1 << (length % 32));
        }
        
        length++;
    }

    // 임의의 원소 위치에 접근
    bool operator[](int i) { return (data[i / 32] & (1 << (i % 32))) != 0; }

    // x번째 위치한 원소 제거
    void remove(int x)
    {
        for (int i = x + 1; i < length; i++)
        {
            int prev = i - 1;
            int curr = i;

            // 만약 curr의 비트가 1이라면
            // prev 의 비트를 1로 만든다.
            if (data[curr / 32] & (1 << (curr % 32)))
            {
                data[prev / 32] |= (1 << (prev % 32));
            }
            else
            {
                // 32비트에서 모두 1인 경우
                unsigned int all_ones_except_prev = 0xFFFFFFFF;
                // XOR 연산, 목표 위치의 비트 외에는 모두 1이다.
                all_ones_except_prev ^= (1 << (prev % 32));
                // 목표 위치의 비트는 0이므로 0으로 설정됨.
                data[prev / 32] &= all_ones_except_prev;
            }
        }
        length--;
    }

    // 현재 벡터의 크기
    int size() { return length; }

    ~Vector()
    {
        if (data)
        {
            delete[] data;
        }
    }
};



int main()
{
    // int를 보관하는 벡터를 만들고 싶을때
    // <> 안에 원하는 타입을 명시
    Vector<int> int_vec;
    int_vec.push_back(3);
    int_vec.push_back(2);

    std::cout << "-------- int vector ----------" << std::endl;
    std::cout << "첫번째 원소 : " << int_vec[0] << std::endl;
    std::cout << "두번째 원소 : " << int_vec[1] << std::endl;

    Vector<std::string> str_vec;
    str_vec.push_back("hello");
    str_vec.push_back("world");
    std::cout << "-------- std::string vector -------" << std::endl;
    std::cout << "첫번째 원소 : " << str_vec[0] << std::endl;
    std::cout << "두번째 원소 : " << str_vec[1] << std::endl;

    Vector<bool> bool_vec;
    bool_vec.push_back(true);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    bool_vec.push_back(false);
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(false);

    std::cout << "-------- bool vector ---------" << std::endl;
    for (int i = 0; i < bool_vec.size(); i++) 
    {
        std::cout << bool_vec[i];
    }
    std::cout << std::endl;

    return 0;
}