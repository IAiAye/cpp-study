#include <iostream>

class Date
{
    int year_;
    int month_;
    int day_;

    public:
        void ShowDate();

        Date()
        {
            std::cout << "기본 생성자 호출!" << std::endl;
            year_ = 2023;
            month_ = 2;
            day_ = 7;
        }

        Date(int year, int month, int day)
        {
            std::cout << "인자 3 개인 생성자 호출!" << std::endl;
            year_ = year;
            month_ = month;
            day_ = day;
        }
};

void Date::ShowDate()
{
    std::cout << year_ << "년 " << month_ << "월 " << day_ << "일" << std::endl;
}

int main()
{
    Date day; // 디폴트 생성자로 정의해준 값이 들어간다.
    day.ShowDate();
    std::cout << std::endl;

    Date day2(2026, 2, 23); // 인자를 넣어준 값으로 생성된다.
    day2.ShowDate();

    return 0;
}