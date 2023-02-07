#include <iostream>

class Point
{

public:
    int x, y;

    Point(int pos_x, int pos_y)
    {
        x = pos_x;
        y = pos_y;
    }
    void ShowPoint()
    {
        std::cout << "(" << x << "," << y << ")" << std::endl;
    }
};

class Geometry
{
private:
    int num_points;
    Point* point_array[100];
public:
    Geometry()
    {
        num_points = 0;
    }

    void AddPoint(const Point &point)
    {
        point_array[num_points ++] = new Point(point.x, point.y);
    }
    void PrintDistance()
    {
        std::cout << point_array[0] << std::endl;
        std::cout << point_array[1] << std::endl;
    }


};

int main()
{
    Point point1(2,3);
    Point point2(3,2);

    point1.ShowPoint();
    point2.ShowPoint();

    Geometry geo;
    geo.AddPoint(point1);
    geo.AddPoint(point2);

    geo.PrintDistance();


    return 0;
}