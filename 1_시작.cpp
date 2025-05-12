// 1_시작.cpp
#include <stdio.h>
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

int main(void)
{
    printf("Hello, C\n");
    return 0;
}