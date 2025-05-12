// 7_함수8.cpp
#include <iostream>
using namespace std;

int square(int x) { return x * x; }
// 실수 타입에 대해서는 위의 함수를 금지하고 싶습니다.

// 방법 1. 선언만 합니다.
// => 링크 오류를 의도합니다.
/*
    Undefined symbols for architecture arm64:
     "square(double)", referenced from:
      _main in 7_함수8-2dc4e1.o
*/
// 이것이 금지되었는지 의도를 전달하기 어렵습니다.

// 방법 2. C++11, Delete Function
/*
7_함수8.cpp:18:8: note: candidate function has been explicitly deleted
   18 | double square(double x) = delete;
      |        ^
*/
double square(double x) = delete;

int main()
{
    // cout << square(3.14) << endl;
}