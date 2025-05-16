// 22_상수멤버함수3.cpp
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
    void Print() const { leftTop.Print(); }

    // 1) 값으로 반환
    //   문제점) 반환용 임시 객체 복사 비용
    //    장점) 외부에서 내부 객체의 상태를 변경하는 것이 불가능합니다.
    // Point GetLeftTop() const { return leftTop; }

    // 2) 참조로 반환
    // const int => const int& / const int*
    // - 상수 타입은 상수 참조 또는 상수 포인터 타입을 통해서
    //   참조해야 합니다.
    // - 참조를 반환할 경우, 값을 변경할 수 없는 상수 멤버 함수와
    //   값을 변경할 수 있는 비상수 멤버 함수를 모두 제공해주는 것이
    //   좋습니다.
    const Point &GetLeftTop() const { return leftTop; }
    Point &GetLeftTop() { return leftTop; }
};

int main()
{
    Rect r{10, 20};

    // 값으로 반환
    // Point pt = r.GetLeftTop();
    // Point pt{r.GetLeftTop()};
    // pt.SetX(100);
}