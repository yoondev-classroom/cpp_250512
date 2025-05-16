// 30_연산자오버로딩3.cpp
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
    };

    ostream cout;
}

// cout 원리
// => 연산자 오버로딩 + 함수 오버로딩
int main()
{
    int n = 42;
    xstd::cout << n;
    // xstd::cout.operator<<(int)

    const char *s = "hello";
    xstd::cout << s;
    // xstd::cout.operator<<(const char*)

    xstd::cout << n << s;
    // xstd::cout.operator<<(n).operator<<(s);
}

//
#if 0
int main()
{
    // cout << 42;
    // cout.operator<<(42);
}
#endif