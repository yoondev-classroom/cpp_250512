#include <iostream>
using namespace std;

// 인라인 함수
// => 함수를 호출하지 않고, 함수의 구현으로 호출부를 기계어 치환합니다.
//    함수 호출 오버헤드를 제거할 수 있습니다.

// 1) 인라인 최적화는 컴파일러 최적화 명령입니다.
// 2) 인라인 함수로 선언되어도, 컴파일러가 무조건 최적화를 수행하지 않습니다.
//   => 컴파일러가 결정하는 경우가 많습니다.

// 3) 간결한 함수에 대해서 인라인 최적화를 사용하는 것이 좋습니다.
//    잘못 사용할 경우, 전체적인 바이너리 기계어 사이즈가 늘어납니다.

// 4) C99 표준에 인라인 함수 문법이 도입되었습니다.
//    C++: inline void foo() {}
//    C  : static inline void foo() {}
inline int square(int x)
{
    return x * x;
}

int main()
{
    int result = square(10);
}