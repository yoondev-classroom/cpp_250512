// 30_연산자오버로딩7.cpp
#include <iostream>
using namespace std;

class Integer
{
    int value;

public:
    // Integer() : value{0} {}
    inline Integer(int n = 0) : value{n} {}

    // void operator++()
    inline Integer &operator++()
    {
        value += 1;
        return *this;
    }

    Integer operator++(int) // 더미 인자가 필요합니다.
    {
        // 1) 현재 상태를 저장합니다.
        Integer temp{*this};

        // 2) 증가합니다.
        value += 1;

        // 3) 값을 반환합니다.
        return temp;
    }

    friend ostream &operator<<(ostream &os, const Integer &v);
};

// 사용자 정의 타입을 cout 등을 통해서 출력하기 위해서는
// 아래와 같은 연산자 재정의 함수를 제공해야 합니다.
ostream &operator<<(ostream &os, const Integer &v)
{
    return os << v.value;
}

int main()
{
    int n1 = 42;

    cout << ++n1 << endl;
    cout << n1++ << endl;

    Integer n2{42};
    cout << ++n2 << endl;
    cout << n2++ << endl;
    // ++n : operator++()
    // n++ : operator++(int)

    // 증가되기 이전의 값을 반환하고, 자신은 증가합니다.
}

#if 0
int main()
{
    int n1{42};
    ++ ++n1;
    // C++: 증가된 자기 자신의 참조
    /*
        mov     DWORD PTR n1$[rsp], 42                    ; 0000002aH

        mov     eax, DWORD PTR n1$[rsp]
        inc     eax
        mov     DWORD PTR n1$[rsp], eax

        mov     eax, DWORD PTR n1$[rsp]
        inc     eax
        mov     DWORD PTR n1$[rsp], eax

    */

    cout << n1 << endl;

    Integer n2{42};
    /*
        mov     edx, 42                             ; 0000002aH
        lea     rcx, QWORD PTR n2$[rsp]
        call    Integer::Integer(int)
    */
    ++ ++n2;
    // n2.operator++().operator++()
    /*
        lea     rcx, QWORD PTR n2$[rsp]
        call    Integer & Integer::operator++(void)                ; Integer::operator++
        mov     rcx, rax
        call    Integer & Integer::operator++(void)
    */

    cout << n2 << endl;
    // cout.operator<<(n2)
    // operator<<(cout, n2)
}

// * 인라인 최적화
/*
        mov     DWORD PTR n1$[rsp], 42                    ; 0000002aH
        mov     eax, DWORD PTR n1$[rsp]
        inc     eax
        mov     DWORD PTR n1$[rsp], eax
        mov     eax, DWORD PTR n1$[rsp]
        inc     eax
        mov     DWORD PTR n1$[rsp], eax

        mov     DWORD PTR n2$[rsp], 42                    ; 0000002aH
        mov     eax, DWORD PTR n2$[rsp]
        inc     eax
        mov     DWORD PTR n2$[rsp], eax
        lea     rax, QWORD PTR n2$[rsp]
        mov     QWORD PTR $T1[rsp], rax
        mov     rax, QWORD PTR $T1[rsp]
        mov     QWORD PTR this$[rsp], rax
        mov     rax, QWORD PTR this$[rsp]
        mov     eax, DWORD PTR [rax]
        inc     eax
        mov     rcx, QWORD PTR this$[rsp]
        mov     DWORD PTR [rcx], eax

*/

#endif

/*
// C
for (int i = 0 ; i < 10; i++) {}

// C++
for (int i = 0 ; i < 10; ++i) {}
*/