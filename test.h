// test.h
// 헤더를 제공할 때는 중복 포함의 문제가 발생하지 않도록
// 해야 합니다.
// => Include Guard

#ifndef TEST_H
#define TEST_H

int add(int a, int b);
void foo();
void goo();

// 정의는 한번만 존재해야 합니다.
// - ODR
struct Point
{
    int x;
    int y;
};

#endif