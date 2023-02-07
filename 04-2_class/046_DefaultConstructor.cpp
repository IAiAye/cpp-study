#include <iostream>

class Date
{
private:
    int year_;
    int month_;
    int day_;
public:
    // Date() = default; 다음과 같이 명시적으로 default 생성자를 사용하라고 표시할 수 도 있다.
    void ShowDate();
    
    Date()
    {
        year_ = 2023;
        month_ = 2;
        day_ = 7;
    }
};

void Date::ShowDate()
{
    std::cout << year_ << "년 " << month_ << "월 " << day_ << "일" << std::endl;
}

int main()
{
    Date day = Date();
    Date day2; // 2. 따라서 인자가 없는 생성자를 호출 하기 위해선 A a ; 꼴로 선언해야한다.
    //Date day3(); // 1. 다음과 같이 선언하면 리턴값이 Date이고 인자가 없는 함수 day3를 정의한 것으로 받아들여진다.

    day.ShowDate();
    day2.ShowDate();

    return 0;
}