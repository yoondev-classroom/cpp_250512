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

#if 0
// test.c
#include <stdio.h>

void foo(void) { printf("foo\n"); }

int main(void)
{
    const int c;
}
#endif

#if 0
void foo(int a, int b) {}
void goo(void) {}

int main()
{
}

/*
0000000000000000 T _foo
0000000000000004 T _goo
0000000000000008 T _main
*/
#endif
#include <stdio.h>
int main()
{
    int n = 10;
    ++n;
    // 연산의 결과는 증가된 값
}