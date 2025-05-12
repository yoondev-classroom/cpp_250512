// main.c
#include <stdio.h>

void foo(void);

void foo(void)
{
    printf("foo2\n");
}

int main(void)
{
    foo();

    return 0;
}