// 7_함수9.cpp
#include <iostream>
using namespace std;

// 반환타입 함수이름(함수 인자 정보) { 함수 구현부 }
#if 0
int add(int a, int b)
{
    return a + b;
}

int main()
{
}
#endif

#if 0
// 포인터
int main()
{
    int n = 10;

    // 모든 변수는 주소를 가집니다.
    cout << &n << endl;

    // 주소를 포인터 변수에 저장할 수 있습니다.
    int *p = &n;

    // 주소를 통해 해당하는 변수의 값을 읽거나 변경할 수 있습니다.
    cout << *p << endl;
    *p = 42;

    cout << n << endl;
}
#endif

#if 0
int main()
{
    int n = 100;
    int *p = &n;
    *p = 10;

    double d = 3.14;
    double *pd = &d;
    *pd = 1.5;

    int x[3]; // int[3]

    // int[3]* px = &x; - X
    // 배열의 기호는 심볼의 오른쪽에 위치합니다.

    int (*px)[3];
    // * -----> [[int][int][int]]

    int *px[3];
    // [ * ][ * ][ * ]
    //   |    |    |
    //  int  int  int
}
#endif

#if 0
int x[3];

using ARR3 = int[3];

// int (*foo())[3]
ARR3 *foo()
{
    return &x; // int (*)[3]
}

// int (*foo())[3]
// - foo()
// - *foo()
// - (*foo())[3]
// - int (*foo())[3]
#endif

// C++11, 함수를 정의하는 새로운 문법이 도입되었습니다.
// => Trailing Return Type

// int add(int a, int b) { return a + b; }

auto add(int a, int b) -> int
{
    return a + b;
}

int x[3];

auto foo() -> int (*)[3]
{
    return &x; // int (*)[3]
}