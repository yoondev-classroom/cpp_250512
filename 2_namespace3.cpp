// 2_namespace3.cpp

#include <iostream>
// #include <stdio.h>
// C의 모든 헤더 파일을 C++ 스타일로 제공하고 있습니다.
// stdio.h  -> cstdio
// string.h -> cstring
// stdlib.h -> cstdlib

#include <cstdio>
// C 표준 라이브러리의 모든 기능을 std 이름 공간을 통해 사용할 수 있습니다.

int main()
{
    std::printf("Hello, C\n");
}