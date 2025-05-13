// 9_레퍼런스.cpp
// * 매우 중요합니다.
#include <iostream>
using namespace std;

#if 0
int main()
{
    int n = 100;

    int *pn = &n;

    *pn = 42;
    cout << *pn << endl;
    cout << n << endl;
}
#endif

// 1. C++에는 레퍼런스 타입이 도입되었습니다.
//   * 기존 메모리에 새로운 이름을 부여합니다.
#if 0
int main()
{
    int n = 100;

    int &rn = n;

    rn = 42;
    cout << n << endl;
    cout << rn << endl;
}
#endif

// 2. 포인터와 레퍼런스의 차이를 이해해야 합니다.
// - 포인터는 주소를 저장하는 변수 입니다.
//  => 주소 참조를 통해 값을 읽거나 변경할 수 있습니다.

// - 레퍼런스는 기존 메모리에 새로운 이름을 부여합니다.
//  => 새로운 이름을 통해 값을 읽거나 변경할 수 있습니다.

int main()
{
    int n = 100;
    int *pn = &n;
    int &rn = n;

    cout << &n << endl;
    cout << &pn << endl;
    cout << &rn << endl;
}