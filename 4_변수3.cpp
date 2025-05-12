// 4_변수3.cpp
#include <iostream>
using namespace std;

#if 0
int main()
{
    double d1 = 3.14;
    cout << d1 << endl;

    int n1 = d1;
    // C++은 실수 타입과 정수 타입간의 암묵적인 변환이 허용됩니다.
    cout << n1 << endl;
}
#endif

#if 0
int main()
{
    double d1{3.14};
    cout << d1 << endl;

    // 1. 실수와 정수 타입간의 암묵적인 변환을 허용하지 않습니다.
    //  => 일관된 초기화를 사용할 때는 명시적인 캐스팅이 필요합니다.
    int n1{static_cast<int>(d1)};
    cout << n1 << endl;

    cout << sizeof(int) << endl;
    cout << sizeof(long) << endl;

    // long n2 = 1000L;
    // int n3 = n2;
    // 정수 타입간의 암묵적인 변환도 위험합니다.

    long n2{1000L};
    int n3{static_cast<int>(n2)};
    // 2. 표현 범위의 크기가 다른 정수간의 암묵적인 변환도 허용되지 않습니다.
    //  - 명시적인 캐스팅이 필요합니다.
}
#endif

// 컴파일러마다 타입의 크기가 달라질 수 있습니다.
// - 64bit: MSVC(long - 4바이트)
//   64bit: GCC/Clang(long - 8바이트)

// C/C++ 표준에서 타입의 크기가 정해져 있는 것은 오직 하나의 타입입니다.
// => char 타입이 1바이트 입니다.
// => 컴파일러와 플랫폼에 따라서 정수 타입의 크기는 달라질 수 있습니다.

#include <stdint.h> // C99

int main()
{
    // int, char, short, long, long long 을 직접 사용하는 것은
    // 좋지 않습니다.
    int8_t a;
    int16_t b;
    int32_t c;

    uint8_t a2;
}