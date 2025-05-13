// 7_함수2.cpp
#include <iostream>
using namespace std;

// C언어는 함수의 입력/출력 타입에 따라서 다른 이름을 사용하고 있습니다.
// 문제점: 내가 사용하는 타입에 맞는 함수가 무엇인지 확인해야 합니다.
#if 0
int squarei(int x) { return x * x; }
double squared(double x) { return x * x; }
long long squarel(long long x) { return x * x; }

int main()
{
    cout << squarei(10) << endl;
    cout << squared(3.14) << endl;
    cout << squarel(100000000000LL) << endl;
}
#endif

// 함수 오버로딩
// : 함수의 이름은 동일하지만, 함수의 인자 정보(인자의 타입, 개수)가 다른 경우 여러 개를 허용합니다.
// 원리 - 인자 정보를 함수의 심볼을 만들 때 사용합니다.

int square(int x) { return x * x; }
double square(double x) { return x * x; }
long long square(long long x) { return x * x; }

// long square(long long x) { return x * x; }
// - 반환 타입만 다를 경우, 오버로딩은 허용되지 않습니다.

/*
000000000000001c T __Z6squared
0000000000000000 T __Z6squarei
0000000000000038 T __Z6squarex
*/

// __Z3fooidc
void foo(int a, double b, char c) {}
// __Z3fooc
void foo(char c) {}

// __Z3foov
extern "C"
{
    // _foo
    void foo() {}
}

int main()
{
    cout << square(10) << endl;
    cout << square(3.14) << endl;
    cout << square(100000000000LL) << endl;
}