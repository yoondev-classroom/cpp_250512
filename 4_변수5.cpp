// 4_변수5.cpp
#include <iostream>
using namespace std;

int main()
{
    int x = 100;

    // x와 동일한 타입의 변수를 만들고 싶습니다.
    // auto x2;

    // C++11, decltype
    decltype(x) x2;
    // int      x2;
}