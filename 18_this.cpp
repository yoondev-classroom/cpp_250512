// 18_this.cpp
#include <iostream>
using namespace std;

#if 0
class Point
{
    int x = 0;
    int y = 0;

public:
    void Set(int a, int b)
    {
        x = a;
        y = b;
    }
};

int main()
{
    Point pt1;
    Point pt2;

    pt1.Set(10, 20);
    pt2.Set(100, 200);
}
#endif

void Set(int a, int b)
{
}

class Point
{
    int x;
    int y;

public:
    // void Set(Point* this, int a, int b)
    void Set(int a, int b)
    {
        this->x = a;
        // this->x = a;
        this->y = b;
        // this->y = b;
    }

    // C++23에서는 멤버 함수를 만들때, 명시적으로 객체를 전달받을 수 있습니다.
    void Set2(this Point &self, int x, int y)
    {
        self.x = x;
        self.y = y;
    }
};

int main()
{
    Point pt;
    pt.Set(10, 20);
    pt.Set2(100, 200);
    /*
        mov     r8d, 20
        mov     edx, 10
        lea     rcx, QWORD PTR pt$[rsp] ; rcx = &pt;
        call    void Point::Set(int,int)
    */

    Set(10, 20);
    /*
        mov     edx, 20
        mov     ecx, 10
        call    void Set(int,int)
    */
}