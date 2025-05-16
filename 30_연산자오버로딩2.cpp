// 30_연산자오버로딩2.cpp
#include <iostream>
using namespace std;

class Point
{
    int x;
    int y;

public:
    Point(int a, int b) : x{a}, y{b} {}
    void Print() const { cout << x << ", " << y << endl; }

    Point operator+(const Point &rhs)
    {
        Point result{x + rhs.x, y + rhs.y};
        return result;
    }

    int GetX() const { return x; }
    int GetY() const { return y; }
};

Point Add(const Point &lhs, const Point &rhs)
{
    Point result{lhs.GetX() + rhs.GetX(), lhs.GetY() + rhs.GetY()};
    return result;
}

// C++에서는 객체를 대상으로 연산자를 사용하였을 경우,
// 약속된 일반 함수 또는 멤버 함수를 호출합니다.
// => 연산자 오버로딩

int main()
{
    Point pt1{10, 20};
    Point pt2{100, 200};

    Point result = pt1 + pt2;
    //  pt1.operator+(pt2);
    //  operator+(pt1, pt2);

    result.Print();

#if 0
    // 1. 일반 함수
    Point result1 = Add(pt1, pt2);
    result1.Print();

    // 2. 멤버 함수
    Point result2 = pt1.Add(pt2);
    result2.Print();
#endif
}

/*
void StartRecording()
{
    InitAudio();
    InitVideo();
    //...
}


*/