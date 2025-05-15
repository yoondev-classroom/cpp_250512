// 19_복사생성자.cpp
#include <iostream>
using namespace std;

// 1) 사용자가 생성자를 1개도 제공하지 않으면, 컴파일러는 기본 생성자를 제공합니다.
// 2) 사용자가 생성자를 1개라도 제공하면, 컴파일러는 기본 생성자를 제공하지 않습니다.
// 3) 사용자가 자신과 동일한 타입의 객체를 인자로 전달받는 생성자(복사 생성자)를 제공하지 않는다면,
//    컴파일러가 멤버를 복사하는 복사 생성자를 제공합니다.

#if 0
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
#endif

#if 0
class Point
{
public:
    Point() { cout << "Point()" << endl; }                          // 기본 생성자
    Point(const Point &) { cout << "Point(const Point&)" << endl; } // 복사 생성자
};

Point pt;

Point &foo()
{
    return pt;
    // 반환용 임시 객체를 복사 생성자를 통해서
    // 생성해서 전달합니다.
}

int main()
{
    foo();
}
#endif

#if 0
void foo(const Point &pt)
{
}

int main()
{
    Point pt;
    foo(pt); // !!
}
#endif

#if 0
int main()
{
    Point pt;

    Point o1 = pt;   // 복사 생성자 호출
    Point o2(pt);    // 복사 생성자 호출
    Point o3 = {pt}; // 복사 생성자 호출
    Point o4{pt};    // 복사 생성자 호출
}
#endif