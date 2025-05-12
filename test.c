// test.c
#if 0
void foo(void) {}
void goo() {} // X - 컴파일 시간에 문제를 확인할 수 없습니다.

int main(void)
{
    // foo(10);
    goo(10);

    return 0;
}
#endif

// test.c
#include <stdio.h>

void foo(void) { printf("foo\n"); }

int main(void)
{
    const int c;
}