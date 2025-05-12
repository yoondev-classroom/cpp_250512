// 4_변수.cpp
#include <iostream>
using namespace std;

// 사용자 정의 타입(구조체)
struct Complex
{
    int re;
    int im;
};
// 8

// 공용체
union Data
{
    int a;
    char c;
}; // 4

// 열거체
enum State
{
    RUNNING,
    STOPPED
};

int main()
{
    struct Complex c1;
    struct Complex c2;

    union Data d1;
    union Data d2;

    enum State s1;
    enum State s2;

    // C++에서는 struct, enum, union을 명시하지 않아도 됩니다.
    // 태그가 타입으로 인식됩니다.
    Complex c3;
    Data d3;
    State s3;
}
