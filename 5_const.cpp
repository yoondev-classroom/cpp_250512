// 5_const.cpp
#include <iostream>
using namespace std;

#if 0
int main()
{
    int n = 10;
    // 변수(Variable): 실행 시간에 변하는 값
    n = 42;

    const int c = 10;
    // 상수(Constant Variable): 실행 시간에 변할 수 없습니다.
    c = 42; // 컴파일 오류!
}
#endif

// 1. C++에서는 const는 반드시 초기화가 필요합니다.
//    C에서는 컴파일 오류가 발생하지 않지만, C++에서는 컴파일 오류가 발생합니다.

// 2. 상수 표현식
//   - 컴파일러가 컴파일 시간에 미리 계산할 수 있는 표현식

// 3. 상수
//   1) 컴파일타임 상수
//   2) 런타임 상수

int main()
{
    const int c = 10;

    int *p = (int *)&c;
    *p = 100;

    printf("%d\n", *p);
    printf("%d\n", c);
}