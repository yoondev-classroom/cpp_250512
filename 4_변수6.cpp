// 4_변수6.cpp
#include <iostream>
using namespace std;

// C/C++ 에는 기존 타입의 별칭을 제공할 수 있는
// 문법이 있습니다.
// - typedef
#if 0
int main()
{
    typedef int INT;
    INT a; // int

    typedef int ARR3[3];
    ARR3 x; // int[3]
    x[0] = 10;
    x[1] = 20;
    x[2] = 30;
}
#endif

// C++11 이후에는 타입의 별칭을 지정하는 새로운 문법이 도입되었습니다.
//  - using
//     * using 선언
//     * using 지시어
//     * using을 통한 타입 별칭
int main()
{
    // typedef int INT;
    using INT = int;
    INT a; // int

    // typedef int ARR3[3];
    using ARR3 = int[3];
    ARR3 x; // int[3]
    x[0] = 10;
    x[1] = 20;
    x[2] = 30;
}