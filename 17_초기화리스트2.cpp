// 17_초기화리스트2.cpp
#include <iostream>
using namespace std;

// * 주의 사항
// - 객체의 멤버가 초기화되는 순서는 초기화 리스트의 순서에 영향을 받지 않습니다.
// - 객체의 멤버가 초기화되는 순서는 멤버가 선언된 순서에 영향을 받습니다.
// => 초기화리스트는 멤버가 선언된 순서대로 작성해야 합니다.
#if 0
class Point
{
    int y;
    int x;

public:
    Point(int a)
        : y{a}, x{y + 10}
    {
    }

    void Print()
    {
        cout << x << ", " << y << endl;
    }
};

int main()
{
    Point pt{10};
    pt.Print();
}
#endif

// C++11, 멤버 초기화
#if 0
class Point
{
    int x = 10;
    int y = 20;

public:
    void Print()
    {
        cout << x << ", " << y << endl;
    }
};

int main()
{
    Point pt;
    pt.Print();
}
#endif

#if 0
class Point
{
    int x = 10;
    int y = 20;
    // 초기화되지 않았을 때의 기본값으로 사용됩니다.

public:
    Point(int a, int b)
        : x{a}, y{b}
    {
    }

    void Print()
    {
        cout << x << ", " << y << endl;
    }
};

int main()
{
    Point pt{100, 200};
    pt.Print();
}
#endif

// 멤버 데이터의 이름을 구분해서 짓습니다.
// - mX, mY
// - m_x, m_y
// - x_, y_  => 표준 권장 형식
// - _x, _y  => 안됩니다. 라이브러리가 사용하는 방식

class Point
{
    int x_;
    int y_;

public:
    Point(int x, int y)
        : x_{x}, y_{y} // OK
    {
        x_ = 10;
    }
};

int main()
{
}
