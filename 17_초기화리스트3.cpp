// 3_초기화리스트3.cpp
#include <iostream>
using namespace std;

class Point
{
    int x_;
    int y_;

public:
    Point(int x, int y)
        : x_{x}, y_{y} {}
};

// 초기화리스트를 반드시 사용해야 하는 경우
// 1) 멤버 데이터가 const 인 경우
// 2) 멤버 데이터가 reference 인 경우
// 3) 멤버 데이터가 기본 생성자를 제공하지 않는 객체인 경우
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