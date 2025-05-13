// 7_함수4.cpp
#include <iostream>
using namespace std;

#if 1
int square(int x)
{
    return x * x;
}
/*
        mov     DWORD PTR [rsp+8], ecx           ; x = ecx
        mov     eax, DWORD PTR x$[rsp]           ; eax = x;
        imul    eax, DWORD PTR x$[rsp]           ; eax = eax * x;
        ret     0                                ; 스택에 저장된 복귀 주소로, 점프합니다.
*/

int main()
{
    int result = square(10);
    //  mov     ecx, 10                       ; ecx = 10
    //  call    int square(int)               ; call의 명령은, 복귀 주소를 스택에 저장하고,
    //                                          실행할 위치로 점프합니다.
    //  mov     DWORD PTR result$[rsp], eax   ; result = eax

    printf("%d\n", result);
}
#endif

#if 0
// 전처리기 매크로
#define PI 3.14

int main()
{
    printf("PI = %lf\n", PI);
}
#endif

// * 매크로 함수를 만들 수 있습니다.
// - 함수 호출 오버헤더를 제거할 수 있습니다.
// - 빈번하게 호출되는 간결한 함수에서 유용합니다.

// * 주의사항
//  => 우선순위 문제가 발생할 수 있습니다.
//  => 우선순위에 문제가 발생하지 않도록 전달된 인자와 치환되는 영역을 모두 괄호로 감싸주어야 합니다.
//  => 매크로 함수에서 ++/-- 연산을 사용할 때, 미정의 동작의 위험성이 존재합니다.

#define SQUARE(x) ((x) * (x))
#if 1
int main()
{
    int result = SQUARE(10);
    //                  ((10) * (10))

    result = SQUARE(5 + 5);
    //              ((5 + 5) * (5 + 5))

    int x = 0;
    result = SQUARE(++x);
    //              ((++x) * (++x)) : 미정의 동작

    printf("%d\n", result);
}
#endif

#if 0
int main()
{
    int x = 0;

    // ++x;
    // x++;

    // int r = x++;
    // r: 0

    int r = ++x;
    // r: 1

    cout << x << endl; // 1
}
#endif