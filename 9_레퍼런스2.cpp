// 9_레퍼런스2.cpp
#include <iostream>
using namespace std;

// * 포인터 변수는 유효성 여부를 체크하기 위해서,
//   유효하지 않은 경우, 0(NULL)으로 초기화해야 합니다.
// * 포인터는 사용하기 전에 반드시 유효성을 체크해야 합니다.
#if 0
int main()
{
    int n;
    // int *pn = &n;
    // int *pn = NULL;
    int *pn = nullptr;

    cout << pn << endl;

    // if (pn != NULL)
    if (pn != nullptr)
    {
        *pn = 42;
    }

    if (pn)
    {
        cout << *pn << endl;
    }
}
#endif

#if 0
// C++에서 포인터와 레퍼런스 모두 사용할 수 있다면,
// 레퍼런스를 사용하는 것이 좋을 때가 있습니다.
int main()
{
    int n;
    int &r = n;
    // int &r; // 컴파일 오류!, 반드시 초기화가 필요합니다.

    // 레퍼런스는 사용하기 전에, 별도의 유효성 체크가 필요하지 않습니다.
}
#endif

#if 0
int *foo()
{
    int x = 10;
    return &x;
}

int main()
{
    int *p = foo();
    *p = 100;           /* 미정의 동작 */
    cout << *p << endl; /* 미정의 동작 */
}
#endif

#if 0
// 레퍼런스로 유효하지 않은 메모리에 대해서 참조가 발생할 가능성도 존재합니다.
int &foo()
{
    int x = 10;
    return x;
}

int main()
{
    int &p = foo();
    p = 100;           /* 미정의 동작 */
    cout << p << endl; /* 미정의 동작 */
}
#endif

// 해결방법 1.
// - 전역 변수를 사용해야 합니다.
//   전역 변수는 프로그램의 끝까지 유효합니다.

// 해결방법 2.
// - 정적 지역 변수

int &foo()
{
    static int x = 10;
    // 함수가 최초에 호출되는 시점에 초기화되고,
    // 프로그램 끝까지 유지됩니다.

    return x;
}

int main()
{
    int &p = foo();
    p = 100;           /* 미정의 동작 */
    cout << p << endl; /* 미정의 동작 */
}