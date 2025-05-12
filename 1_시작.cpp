// 1_시작.cpp

// Build: Ctrl + F7
// Build + Run: Ctrl + F5
// - 모든 소스를 컴파일하고, 링크해서, 실행 파일을
//   만듭니다.

// 1. 확장자
//   C: .c
// C++: .cpp, .cc, .cxx ...

// 2. 컴파일러
// 소스 코드 -> 오브젝트 파일(*.o, *.obj)
//        컴파일
// 1.cpp -> 1.o
// 2.cpp -> 2.o -> 링크 -> a.exe / a.out(실행 파일)
// 3.cpp -> 3.o

// 3. 컴파일러 종류
// MSVC: Microsoft Visual C/C++ Compiler
//  GCC: GNU C/C++ Compiler
// LLVM: Clang

// 4. C++ 표준
// 1983년: C++ 탄생
//----------------
// 1998년: 1차 표준안, C++98
// 2003년: 1차 표준안, 개정안 - C++03
// 2011년: 2차 표준안, C++11
// 2014년: 2차 표준안, 개정안 - C++14 => Modern C++
// 2017년: C++17
// 2020년: C++20
// 2023년: C++23

// https://github.com/yoondev-classroom/cpp_250512

// 5. C++에서 C의 모든 기능을 사용할 수 있습니다.
// 6. C의 표준하고, C++ 안에서의 C의 표준은 다릅니다.

// /* /* */ */
// -> 중첩이 되지 않습니다.

#if 0
#include <stdio.h>

// int main(void)
int main(void)
{
    printf("Hello, C\n");
    return 0;
}
#endif
#if 0
void foo(void) {} // OK
void goo() {}     // OK

int main()
{
    // foo(10);
    // goo(10);

    // return 0;
    // C++ 컴파일러는 메인 함수에서, return 0를
    // 자동으로 처리하므로, 생략 가능합니다.
}
#endif

#include <stdio.h>

int main()
{
    printf("Hello, C\n");
}