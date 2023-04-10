#include <iostream>
#include <string>

using namespace std;

class Vector
{
private:
    string* data;
    int capacity;
    int length;

public:
    Vector(int n = 1);
    
    void push_back(string s);

    string operator[](int i);

    void remove(int x);

    int size();

    ~Vector();
};

Vector::Vector(int n) : data(new string[n]), capacity(n), length(0) {} 
// 클래스 내부에서 디폴트 인자를 명시했다면 함수 본체에서는 사용하면 안된다. 반대의 경우도 마찬가지.
void Vector::push_back(string s)
{
    if (capacity <= length)
    {
        string* temp = new string[capacity * 2];
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

string Vector::operator[](int i) { return data[i]; }

void Vector::remove(int x)
{
    for (int i = x + 1; i < length; i++)
    {
        data[i - 1] = data[i];
    }
    length--;
}

int Vector::size() { return length; }

Vector::~Vector()
{
    if (data)
    {
        delete[] data;
    }
}