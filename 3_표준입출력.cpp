// 3_표준입출력.cpp
#include <iostream>
using namespace std;

#if 0
int main()
{
    // int n = 0xFAFA;
    //        1111 1010 1111 1010

    // C++11, 이진수 상수를 지정할 수 있습니다.
    //  단일 따옴표를 통해 가독성을 높일 수 있습니다.
    int n = 0b1111'1010'1111'1010;
    int x = 200'000'000;

    printf("%x\n", n);
    printf("%X\n", n);

    // cout << n << endl;
    cout << hex << n << endl;
    cout << hex << uppercase << n << endl;
    // hex: IO 조정자(Manipulator)
}
#endif

#if 0
int main()
{
    // int n = 10000;
    // long n = 10000;
    int n = 10000;
    char ch = 'A';

    // 변수의 타입이 변경될 때마다, 서식의 코드도 변경되어야 합니다.
    // printf("%lld,%c\n", n, ch);
    cout << n << ", " << ch << endl;

    printf("n = %d, ch = %c\n", n, ch);
    cout << "n = " << n << ", " << "ch = " << ch << endl;
    // 출력의 형태로 표현할 때 번거롭습니다.
}
#endif

#if 0
// C++23에서 새로운 출력의 라이브러리가 도입되었습니다.
#include <print>

int main()
{
    int n = 10;
    char ch = 'A';
    std::println("n={}, ch={}\n", n, ch);
}
#endif

// 1. cout은 변수의 타입이 변경되어도, 자동으로 처리됩니다.
//    원리가 무엇인가?

// 2. cin은 주소를 전달받지 않고도, 변수의 값을 변경할 수 있습니다.
//    원리가 무엇인가?

// 3. endl의 정체는 무엇인가?

int main()
{
    long n = 10;
    printf("%ld\n", n);

    cout << n << endl;

    int x;
    scanf("%d", &x);

    cin >> x;
}