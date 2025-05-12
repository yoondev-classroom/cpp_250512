// 7_함수6.cpp
#include <iostream>
using namespace std;

// int square(int x) { return x * x; }
// double square(double x) { return x * x; }
// long long square(long long x) { return x * x; }

// 함수의 인자와 반환 타입만 다르고, 함수의 구현(알고리즘) 동일합니다.
// => 함수 템플릿(Template)
//  : 다른 언어에서는 Generic 이라는 이름으로 제공되는 문법과 유사하지만,
//    각 언어마다 제공되는 방식은 다릅니다.

// * 문제점
//  : 필요한 타입만큼의 코드를 생성해야 하기 때문에,
//    실제로 많은 코드 메모리 사용량이 존재할 수 있습니다.
//    인라인 최적화가 가능하면, 해당 문제를 발생하지 않습니다.

template <typename TYPE>
TYPE square(TYPE x) { return x * x; }

// int square(int x) { return x * x; }
// double square(double x) { return x * x; }
// long long square(long long x) { return x * x; }

int main()
{
    cout << square(10) << endl;
    // TYPE -> int 로 결정해서, 코드를 생성합니다.

    cout << square(3.14) << endl;
    // TYPE -> double로 결정해서, 코드를 생성합니다.

    cout << square(100000000000L) << endl;
    // TYPE -> long long
}