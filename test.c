// test.c
void foo(void) {}
void goo() {} // X - 컴파일 시간에 문제를 확인할 수 없습니다.

int main(void)
{
    // foo(10);
    goo(10);

    return 0;
}