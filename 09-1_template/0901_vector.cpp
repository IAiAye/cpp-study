#include <iostream>
#include <string>

// string을 담는 벡터지만, int, char을 담고 싶을때는 일일이 다 바꿔주어야 한다.
// 템플릿의 필요성
class Vector
{
    std::string* data;
    int capacity;
    int length;

public:
    // 생성자
    Vector(int n = 1) : data(new std::string[n]), capacity(n), length(0) {}

    // 맨 뒤에 원소 추가
    void push_back(std::string s)
    {
        // 용량이 길이보다 작거나 같을때 늘려줘야 한다.
        if (capacity <= length)
        {
            std::string* temp = new std::string[capacity * 2];
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
    std::string operator[](int i) { return data[i]; }

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
