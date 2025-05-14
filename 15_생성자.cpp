// 15_생성자.cpp
#include <iostream>
using namespace std;

#if 0
// 1) 사용자가 생성자를 아무것도 제공하지 않으면,
//    컴파일러가 아무일도 하지 않는 인자 없는 생성자를
//    제공합니다.
class Point
{
    int x;
    int y;
    // public:
    //    Point() {}  // 기본 생성자(Default Constructor)
};

int main()
{
    Point pt; // 인자 없는 생성자 호출
}
#endif

// 2) 사용자가 생성자를 1개라도 제공하면,
//    컴파일러는 기본 생성자를 제공하지 않습니다.
#if 0
class Point
{
    int x;
    int y;

public:
    Point(int a, int b)
    {
        x = a;
        y = b;
    }
};

int main()
{
    // Point pt; // 오류!
    Point pt{10, 20};
}
#endif

// 3) 생성자는 오버로딩이 가능합니다.
//  => 객체를 생성하는 다양한 방법을 제공할 수 있습니다.
class Point
{
    int x;
    int y;

public:
    // 기본 생성자를 제공하는 것은 편리합니다.
    Point()
    {
        x = 0;
        y = 0;
    }

    Point(int a, int b)
    {
        x = a;
        y = b;
    }
};

int main()
{
    // Point pt; // 오류!
    Point pt{10, 20};
}