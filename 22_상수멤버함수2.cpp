// 22_상수멤버함수2.cpp
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

    void Print() const { cout << x << ", " << y << endl; }
};

class Rect
{
    Point leftTop;

public:
    Rect(int x, int y) : leftTop{x, y} {}

    // Point GetLeftTop() const { return leftTop; }

    // * 핵심: 내부 멤버의 참조/포인터를 반환할 때,
    //        상수 멤버 버전과 비상수 멤버 버전을 동시에 제공하는 것이 좋습니다.

    // 상수 멤버 함수는 내부의 멤버를 const 취급합니다.
    // 내부의 const 멤버를 참조로 반환하려면, 일반 레퍼런스가 아니라
    // const 레퍼런스로 반환해야 합니다.
    const Point &GetLeftTop() const
    {
        return leftTop;
    }

    // C++에서는 상수 멤버 함수와 비상수 멤버 함수를 동시에 제공할 수 있습니다.
    Point &GetLeftTop()
    {
        return leftTop;
    }

    void Print() const { leftTop.Print(); }
};

// * 상수 멤버 함수와 비상수 멤버 함수를 모두 제공한 경우
//       Point& -> 비상수 멤버 함수 호출
// const Point& -> 상수 멤버 함수 호출
//       Point* -> 비상수 멤버 함수 호출
// const Point* -> 상수 멤버 함수 호출

// * 상수 멤버 함수만 제공한 경우
//       Point& -> 상수 멤버 함수 호출
// const Point& -> 상수 멤버 함수 호출
//       Point* -> 상수 멤버 함수 호출
// const Point* -> 상수 멤버 함수 호출

// * 비상수 멤버 함수만 제공한 경우
//       Point& -> 비상수 멤버 함수 호출
// const Point& -> X
//       Point* -> 비상수 멤버 함수 호출
// const Point* -> X

int main()
{
    Rect r{10, 20};
    // Point pt = r.GetLeftTop();

    Rect &r1 = r;
    const Rect &r2 = r;

    Point &pt = r1.GetLeftTop();
    pt.SetX(100);
    pt.Print();

    const Point &pt1 = r2.GetLeftTop();
    pt1.Print();
}