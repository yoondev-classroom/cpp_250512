// 10_캐스팅.cpp
#include <iostream>
using namespace std;

#if 1
// 캐스팅이 필요한 경우
// 1) 정수 타입과 실수 타입간의 변환
// 2) 정수 타입간의 변환
// 3) void*를 구체적인 포인터 타입으로의 변환
// 4) 메모리 재해석하는 목적으로 포인터 타입으로의 변환
// 5) const의 타입의 불일치 문제를 해결하기 위해서

int main()
{
    double d{3.14};
    int n{(int)d}; // C의 명시적인 캐스팅

    void *pv = NULL;
    // 가르키는 대상체의 타입을 모르는 포인터 타입입니다.
    // void*는 모든 타입의 주소를 담을 수 있습니다.
    pv = &d;

    // 연산을 수행할 수 없습니다.
    cout << *(double *)pv << endl;

    int x = 0x12345678;
    char *px = (char *)&x;
    printf("%x %x %x %x\n", px[0], px[1], px[2], px[3]);

    // 메모리 재해석은 주의해서 사용해야 합니다.
    long *px2 = (long *)&x;
    *px2 = 100000000000; // !!
}
#endif

// 포인터의 타입은 포인터 연산의 단위를 결정합니다.
//  int*: * ----> int ; 4바이트 단위 연산
// char*: * ----> char ; 1바이트 단위 연산
// double* ; 8
// long long ; 8
#if 0
int main()
{
    int n = 42;
    int *pn = &n;

    *pn = 100;
}
#endif

#if 0
int main()
{
    //          px
    //          |
    int x[5] = {10, 20, 30, 40, 50};

    // int *px = &x[0];
    int *px = x;
    cout << *(px + 0) << endl;
    cout << *(px + 1) << endl;
    cout << *(px + 2) << endl;
    cout << *(px + 3) << endl;
    cout << *(px + 4) << endl;

    cout << px[0] << endl;
    cout << px[1] << endl;
    cout << px[2] << endl;
    cout << px[3] << endl;
    cout << px[4] << endl;

    // 배열 x[5]
    // - 배열의 이름(x)는 배열의 첫번째 원소의 시작 주소로 해석됩니다.
}
#endif

#if 0
// 배열을 함수로 전달할 때, 배열의 첫번째 원소의 시작 주소를 전달합니다.
// void Increment(int x[3]) // int* x
void Increment(int *x)
{
    for (int i = 0; i < 3; ++i)
    {
        x[i] += 10;
        // x[i] = x[i] + 10
    }
}

int main()
{
    int x[3] = {10, 20, 30};
    cout << sizeof(x) << endl; // 12

    Increment(x); // Increment(&x[0])

    for (auto e : x)
    {
        cout << e << endl;
    }
}
#endif