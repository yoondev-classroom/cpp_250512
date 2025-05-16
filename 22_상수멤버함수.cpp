// 22_상수멤버함수.cpp
#include <iostream>
using namespace std;

// 핵심
// : 객체의 상태를 변경하지 않는 모든 멤버 함수는
//   반드시 상수 멤버 함수로 만들어야 합니다.

class Point
{
    int x;
    int y;

public:
    Point(int a, int b) : x{a}, y{b} {}

    // 상수 멤버 함수 - 멤버 함수 내에서 객체의 상태를 변경할 수 없습니다.
    //  : 모든 멤버를 const 취급합니다.
    //    int x ---> const int x
    //    int y ---> const int y
    void Print() const
    {
        // x = 100;
        cout << x << ", " << y << endl;
    }

    void SetX(int a)
    {
        x = a;
    }

    void SetY(int a)
    {
        y = a;
    }
};

// const& / const*는 상수 멤버 함수만 호출이 가능합니다.
void foo(const Point &pt)
{
    pt.Print(); // OK
    // pt.SetX(10); // 허용되지 않습니다.
}

void foo(const Point *pt)
{
    pt->Print();
    // pt->SetX(10); // 허용하지 않습니다.
}

void goo(Point &p)
{
    p.SetX(10); // OK
    p.Print();  // OK
}

void goo(Point *p)
{
    p->SetX(10); // OK
    p->Print();  // OK
}

#if 0
int main()
{
    Point pt{10, 20};
    foo(pt);

    Point &r = pt;
    r.SetX(100);
    r.SetY(200);
    r.Print();

    Point *p = &pt;
    p->SetX(100);
    p->SetY(200);
    p->Print();

    // 핵심: 상수 포인터 및 참조는 상수 멤버 함수만 호출이 가능합니다.
    const Point &cr = pt;
    // cr.SetX(100); - 에러
    // cr.SetY(200); - 에러
    cr.Print();

    const Point *cp = &pt;
    // cp->SetX(100); - 에러
    // cp->SetY(200); - 에러
    cp->Print();
}
#endif

#if 0
int main()
{
    int n = 100;

    int *pn1 = &n;       // "RW"
    const int *pn2 = &n; // "R"

    // int*   -> const int*
    //  "RW"        "R"     : 암묵적인 변환 허용
    const int *pn3 = pn1;

    // const int* -> int*   : 암묵적인 변환 허용 X
    //   "R"          "RW"
    int *pn4 = const_cast<int *>(pn2);
}
#endif

int main()
{
    int n = 100;

    int &r = n;
    const int &cr = n;

    // int& -> const int&
    // "RW"      "R"
    const int &cr2 = r; /* OK */

    // const int& -> int&
    //   "R"         "RW"  - 명시적인 캐스팅이 필요합니다.
    int &r2 = const_cast<int &>(cr);
}