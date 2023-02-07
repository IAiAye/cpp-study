#include <iostream>
#include <cmath>

using namespace std;
class Point
{
int x, y;

public:

    Point(int pos_x, int pos_y)
    {
        x = pos_x;
        y = pos_y;
    }
    int GetX() const {return x;}
    int GetY() const {return y;}

    void ShowPoint()
    {
        cout << "(" << x << "," << y << ")" << endl;
    }
};

class Geometry
{
private:
    int num_points;
    Point* point_array[100]; //Point 클래스의 pointer 생성
public:
    Geometry()
    {
        num_points = 0;
    }
    ~Geometry() // 소멸자
    {
        for (int i = 0; i < num_points; i++)
        {
            delete point_array[i];
        }
    }

    void AddPoint(const Point &point)
    {
        point_array[num_points ++] = new Point(point.GetX(), point.GetY());
    }
    void PrintDistance();
    void PrintNumMeets();
};

void Geometry::PrintDistance()
{
    for (int i = 0; i < num_points - 1; i++)
    {
        for (int j = i + 1; j < num_points; j++)
        {
            cout << i + 1 << "번째 점과 " << j + 1 << "번째 점의 거리는 " 
            << sqrt(pow(point_array[i]->GetX() - point_array[j]->GetX(),2) + pow(point_array[i]->GetY() - point_array[j]->GetY(),2))
            << "입니다." << endl;
        }
           
    }
}
void Geometry::PrintNumMeets()
{
    if (num_points < 4)
    {
        cout << "점의 개수가 교점을 생성하기에 적습니다." <<endl;
    }
    else
    {
        for (int i = 0; i < num_points - 3; i++)
        {
            for (int j = 0; j < num_points - 2; j++)
            {
                for (int k = 0; k < num_points - 1; k++)
                {
                    for (int m = 0; m < num_points; m++)
                    {
                        // 교점의 정의가 모호하여 포기.
                    }
                    
                }
                
            }
            
        }
        
    }
    
}


int main()
{
    Point pos1(0,0);
    Point pos2(3,4);
    Point pos3(12,5);
    Point pos4(16,9);

    pos1.ShowPoint();
    pos2.ShowPoint();
    pos3.ShowPoint();
    pos4.ShowPoint();

    Geometry geo;
    geo.AddPoint(pos1);
    geo.AddPoint(pos2);
    geo.AddPoint(pos3);
    geo.AddPoint(pos4);

    geo.PrintDistance();


    return 0;
}