#include <iostream>

class Date
{
private: 
    int year_;
    int month_;
    int day_;

public: 
    void SetDate(int year, int month, int date)
    {
        year_ = year;
        month_ = month;
        day_ = date;
    }
    void AddDay(int inc)
    {
        day_ += inc;
        while (day_ > 28)
        {
            if (month_ == 2)
            {
                if (year_ % 4 == 0) // 윤년 확인
                {
                    if (day_ == 29)
                    {
                        break;
                    }
                    day_ -= 29;
                    month_ += 1;
                }
                else
                {
                    day_ -= 28;
                    month_ += 1;
                }
                
            }
            if (month_ == 4 or month_ == 6 or month_ == 9 or month_ == 11)
            {
                if (day_ < 31)
                {
                    break;
                }
                day_ -= 30;
                month_ += 1;
            }
            if (month_ == 1 or month_ == 3 or month_ == 5 or month_ == 7 or month_ == 8 or month_ == 10 or month_ == 12)
            {
                if (day_ < 32)
                {
                    break;
                }
                day_ -= 31;
                month_ += 1;
            }
            if (month_ > 12)
            {
                month_ -= 12;
                year_ += 1;
            }
        }
    }
    void AddMonth(int inc)
    {
        month_ += inc;
        while (month_ > 12)
        {
            month_ -= 12;
            year_ += 1;
        }
    }
    void AddYear(int inc)
    {
        year_ += inc;
    }

    void ShowDate()
    {
        std::cout << year_ << "년 " << month_ << "월 " << day_ << "일" << std::endl;
    }

};

int main()
{
    Date date;

    date.SetDate(2023, 2, 3);
    date.AddYear(1);
    date.AddDay(28);
    date.AddMonth(-1);

    date.ShowDate();
    return 0;
}