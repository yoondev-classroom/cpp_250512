// 4_변수2.cpp
#include <iostream>
using namespace std;

#if 0
int main()
{
    int n1;
    // 지역 변수는 초기화하는 것이 좋습니다.

    // 지역 변수를 초기화하지 않으면, 쓰레기값을 가집니다.
    // printf("%d\n", n1);
}
#endif

struct Point
{
    int x;
    int y;
};

#if 0
int main()
{
    // 복사 초기화(Copy Initialization)
    int n1 = 42;
    int x1[3] = {10, 20, 30};
    Point pt1 = {10, 20};

    // 직접 초기화(Direct Initialization)
    int n2(42);
    int x2[3]{10, 20, 30};
    Point pt2{10, 20};
}
#endif

// C++11, Uniform Initialization(일관된 초기화)
int main()
{
    // 복사 초기화(Copy Initialization)
    int n1 = {42};
    int x1[3] = {10, 20, 30};
    Point pt1 = {10, 20};

    // 직접 초기화(Direct Initialization)
    int n2{42};
    int x2[3]{10, 20, 30};
    Point pt2{10, 20};
}