// 19_복사생성자5.cpp
#include <iostream>
using namespace std;

class Point
{
    int x;
    int y;

public:
    Point(int a, int b)
        : x{a}, y{b} {}

    // Setter
    void SetX(int a) { x = a; }
    void SetY(int a) { y = a; }

    void Print() { cout << x << ", " << y << endl; }

    Point(const Point &rhs)
        : x{rhs.x}, y{rhs.y} { cout << "복사!" << endl; }
};

class Rect
{
    Point leftTop;

public:
    Rect(int x, int y) : leftTop{x, y} {}

    // Point &GetLeftTop() { return leftTop; }
    Point GetLeftTop() const { return leftTop; }

    void Print() { leftTop.Print(); }
};

int main()
{
    Rect r{10, 20};
    // Point &pt = r.GetLeftTop();
    Point pt = r.GetLeftTop();

    pt.SetX(42);
    pt.SetY(42);

    r.Print();

    // Point pt = r.GetLeftTop();
}