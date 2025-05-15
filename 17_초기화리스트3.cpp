// 3_초기화리스트3.cpp
#include <iostream>
using namespace std;

// 초기화리스트를 반드시 사용해야 하는 경우
// 1) 멤버 데이터가 const 인 경우
// 2) 멤버 데이터가 reference 인 경우
// 3) 멤버 데이터가 기본 생성자를 제공하지 않는 객체인 경우

#if 0
class Point
{
    int x_;
    int y_;

public:
    Point(int x, int y)
        : x_{x}, y_{y} {}
};


class Rect
{
    Point leftTop;

public:
    // Rect() : leftTop{} {}
    // Rect() : leftTop{10, 20} {}

    Rect(int x, int y) : leftTop{x, y} {}
};

int main()
{
    // Rect r;
    Rect r{10, 20};
}
#endif

class Point
{
    int x;
    int y;

public:
    Point() : x{0}, y{0} {}
    Point(int a) { cout << "Point(int)" << endl; }
};

class Rect
{
    Point leftTop;

public:
    // Rect() : leftTop{} {}
    // 컴파일러는 멤버 객체를 초기화할 때, 기본 생성자를 호출하는 코드를
    // 생성합니다.
    // 하지만 멤버 객체가 기본 생성자를 제공하지 않을 경우,
    // 문제가 발생합니다.
    // => 멤버 객체가 기본생성자를 제공하지 않는 경우,
    //    사용자는 반드시 초기화리스트를 통해 명시적으로 해당 객체를 초기화하는 코드를
    //    작성해야 합니다.

    Rect() : leftTop{42} {}
};

int main()
{
    Rect r;

    // Point pt;
}