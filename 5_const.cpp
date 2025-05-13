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

// 2. 상수(const)는 초기화 이후에 값을 변경할 수 없습니다.

// 2. 상수 표현식
//   - 컴파일러가 컴파일 시간에 미리 계산할 수 있는 표현식

// 3. 상수
//   1) 컴파일타임 상수
//   - 컴파일 시간에 상수의 초기값을 컴파일러가 알 수 있을 때
//   - 상수의 값을 읽기 위해서 메모리에 접근할 필요가 없습니다.
//   - 상수 표현식으로 취급됩니다.

//   2) 런타임 상수
//   - 컴파일 시간에 상수의 초기값을 컴파일러가 알 수 없을 때
//   - 상수의 값을 읽기 위해서는 메모리에 접근해야 합니다.

// C++11에서 constexpr 키워드가 추가되었습니다.
// 상수 표현식에 사용할 수 있는 키워드입니다.
#if 1
int main()
{
    // constexpr const int c1 = 10; // 컴파일 타임 상수
    constexpr int c1 = 10;

    int n = 20;
    const int c2 = n; // 런타임 상수

    printf("%d\n", c1);
    printf("%d\n", c2);
}
#endif
