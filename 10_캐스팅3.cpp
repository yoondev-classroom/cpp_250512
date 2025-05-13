// 10_캐스팅.cpp
#include <iostream>
using namespace std;

// 캐스팅이 필요한 경우
// 1) 정수 타입과 실수 타입간의 변환
// 2) 정수 타입간의 변환
// 3) void*를 구체적인 포인터 타입으로의 변환
// 4) 메모리 재해석하는 목적으로 포인터 타입으로의 변환
// 5) const의 타입의 불일치 문제를 해결하기 위해서

// C++은 용도와 목적에 따라서 4개의 캐스팅 연산을 제공하고 있습니다.
// 1) static_cast
//   - 가장 일반적인 캐스팅 연산자
//   - 안전하고, 일반적인 연산에서 보편적으로 사용할 수 있습니다.

// 2) reinterpret_cast
//   - 메모리 재해석 캐스팅 연산자

// 3) const_cast
//   - 메모리의 상수성을 제거하는 캐스팅 연산자
//   - 타입의 불일치 문제를 해결하기 위해서 사용합니다.

// 4) dynamic_cast

int main()
{
    double d{3.14};
    int n{static_cast<int>(d)}; // C의 명시적인 캐스팅

    void *pv = NULL;
    // 가르키는 대상체의 타입을 모르는 포인터 타입입니다.
    // void*는 모든 타입의 주소를 담을 수 있습니다.
    pv = &d;

    // 연산을 수행할 수 없습니다.
    cout << *static_cast<double *>(pv) << endl;

    int x = 0x12345678;
    char *px = reinterpret_cast<char *>(&x);
    printf("%x %x %x %x\n", px[0], px[1], px[2], px[3]);

    // 메모리 재해석은 주의해서 사용해야 합니다.
    long *px2 = reinterpret_cast<long *>(&x);
    *px2 = 100000000000; // !!

    const char *s = "hello";
    // char *s2 = static_cast<char *>(s);
    // char *s2 = reinterpret_cast<char *>(s);
    char *s2 = const_cast<char *>(s);
}
