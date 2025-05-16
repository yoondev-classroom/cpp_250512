// 30_연산자오버로딩6.cpp
#include <iostream>
using namespace std;

namespace xstd
{
    // cout의 타입은 ostream 입니다.
    class ostream
    {
    public:
        // void operator<<(int n) { printf("%d", n); }
        // void operator<<(const char *s) { printf("%s", s); }

        ostream &operator<<(int n)
        {
            printf("%d", n);
            return *this;
        }

        ostream &operator<<(const char *s)
        {
            printf("%s", s);
            return *this;
        }

        ostream &operator<<(ostream &(*fp)(ostream &os))
        {
            return fp(*this);
        }
    };

    ostream cout;

    // IO 조정자
    ostream &endl(ostream &os)
    {
        os << "\n";
        return os;
    }

}

xstd::ostream &menu(xstd::ostream &os)
{
    os << "1.짜장면" << xstd::endl;
    os << "2.짜장면" << xstd::endl;
    os << "3.짜장면" << xstd::endl;
    return os;
}

// cout 원리
// => 연산자 오버로딩 + 함수 오버로딩
int main()
{
    int n = 42;
    xstd::cout << n << xstd::endl;

    xstd::cout << menu;

    // xstd::cout << "1. 짜장면" << xstd::endl;
    // xstd::cout << "2. 짜장면" << xstd::endl;
    // xstd::cout << "3. 짜장면" << xstd::endl;

    // cout << endl;
    // cout.operator<<(endl);
    //  : endl은 함수입니다.
}