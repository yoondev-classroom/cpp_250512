// 12_nullptr.cpp
#include <iostream>
using namespace std;

// #define NULL ((void*)0)

#if 0
void foo(int n) { cout << "int" << endl; }
void foo(int *p) { cout << "int*" << endl; }

int main()
{
    // 1. 정수 0은 포인터 타입으로의 암묵적인 변환을 허용합니다.
    // int *p = 0;
    // int *p = NULL;

    foo(0);
    // foo(NULL); - 타입 안정성이 없다.
}
#endif

// C++11 부터, NULL을 대체하는 새로운 값이 추가되었습니다.
// => nullptr

void foo(int n) { cout << "int" << endl; }
void foo(int *p) { cout << "int*" << endl; }

int main()
{
    foo(0);
    foo(nullptr);

    // int *p1 = nullptr;
    int *p1{nullptr};
    if (p1)
    {
        cout << "유효합니다." << endl;
    }
    else
    {
        cout << "유효하지 않습니다." << endl;
    }
}