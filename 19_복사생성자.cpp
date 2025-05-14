// 19_복사생성자.cpp
#include <iostream>
using namespace std;

// 1) 사용자가 생성자를 1개도 제공하지 않으면, 컴파일러는 기본 생성자를 제공합니다.
// 2) 사용자가 생성자를 1개라도 제공하면, 컴파일러는 기본 생성자를 제공하지 않습니다.
// 3) 사용자가 자신과 동일한 타입의 객체를 인자로 전달받는 생성자(복사 생성자)를 제공하지 않는다면,
//    컴파일러가 멤버를 복사하는 복사 생성자를 제공합니다.

class Point
{
    int x;
    int y;

public:
    Point(int a, int b)
        : x{a}, y{b} {}

    // 컴파일러가 제공하는 복사 생성자의 형태
    Point(const Point &rhs)
        : x{rhs.x}, y{rhs.y}
    {
        cout << "Point(const Point&)" << endl;
    }

    void Print() { cout << x << ", " << y << endl; }
};

int main()
{
    Point pt1{10, 20};
    pt1.Print();

    Point pt2 = {pt1}; // 복사 생성자
    pt2.Print();

    Point pt3{pt1}; // 복사 생성자
    pt3.Print();
}