#include <iostream>

class Date
{
int year_;
int month_; // 1~12
int day_; // 1~31

public: 
    void SetDate(int year, int month, int day);
    void AddDay(int inc);
    void AddMonth(int inc);
    void AddYear(int inc);

    int GetCurrentMonthTotalDays(int year, int month);

    void ShowDate();

    Date(int year, int month, int day) // 3. 생성자 : 객체 생성시 자동으로 호출되는 함수.
    {
        year_ = year;
        month_ = month;
        day_ = day;
    }
};

// 클래스가 길어지기때문에 클래스 함수는 밖에서 선언하는게 일반적이다.

void Date::SetDate(int year, int month, int day)
{
    year_ = year;
    month_ = month;
    day_ = day;
}

int Date::GetCurrentMonthTotalDays(int year, int month)
{
    static int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month != 2)
    {
        return month_days[month - 1];
    }
    else if (year % 4 == 0 && year != 0)
    {
        return 29; // 윤년 확인
    }
    else
    {
        return 28;
    }
}

void Date::AddDay(int inc)
{
    while (1)
    {
        int current_month_total_days = GetCurrentMonthTotalDays(year_, month_);

        if (day_ + inc <= current_month_total_days)
        {
            day_ += inc;
            break;
        }
        else
        {
            inc -= ( current_month_total_days - day_ ) + 1; // 한달을 넘길만큼만 inc에서 차감.
            day_ = 1;
            AddMonth(1);
        }
        
    }
}

void Date::AddMonth(int inc)
{
    month_ += inc;
    while (month_ > 12)
    {
        month_ -= 12;
        year_ += 1;
    }
}

void Date::AddYear(int inc){ year_ += inc; }

void Date::ShowDate()
{
    std::cout << year_ << "년 " << month_ << "월 " << day_ << "일" << std::endl;
}

int main()
{
    // Date date; // 2. 이 쓰레기 값을 막기 위해 생성자를 사용할 수 있다.
    Date date(2011, 3, 1); // 4. 생성자에 인자를 넣어주는 모습.
    // Date date = Date(2011, 3, 1) 다음과 똑같은 방법이다.

    date.SetDate(2023, 2, 3); //1. 생성후 초기화는 필수다. 이를 안해주면 쓰레기값이 나온다.
    date.AddYear(1);
    date.AddDay(28);
    date.AddMonth(-1);

    date.ShowDate();
    return 0;
}

/*
이때의 쓰레기 값은 디폴트 생성자에 의해 생성되는 것이다.
따라서 우리는 4번 과정에서 인자를 넣어주지 않고, 디폴트 생성자를 변경하여 기본 값을 만들어 줄 수 있다.
*/