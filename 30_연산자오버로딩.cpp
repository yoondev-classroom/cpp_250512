// 30_연산자오버로딩.cpp
#include <iostream>
using namespace std;

class Point
{
    int x;
    int y;

public:
    Point(int a, int b) : x{a}, y{b} {}
    void Print() const { cout << x << ", " << y << endl; }

    // Point Add(Point* this, const Point& rhs)
    Point Add(const Point &rhs)
    {
        Point result{x + rhs.x, y + rhs.y};
        return result;
    }

    // friend Point Add(const Point &lhs, const Point &rhs);
    int GetX() const { return x; }
    int GetY() const { return y; }
};

Point Add(const Point &lhs, const Point &rhs)
{
    // Point result{lhs.x + rhs.x, lhs.y + rhs.y};
    Point result{lhs.GetX() + rhs.GetX(), lhs.GetY() + rhs.GetY()};
    return result;
}

int main()
{
    Point pt1{10, 20};
    Point pt2{100, 200};

    // 1. 일반 함수
    Point result1 = Add(pt1, pt2);
    result1.Print();

    // 2. 멤버 함수
    Point result2 = pt1.Add(pt2);
    //              Point::Add(&pt1, pt2)
    result2.Print();
}