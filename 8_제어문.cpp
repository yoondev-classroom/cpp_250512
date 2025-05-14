// 8_제어문.cpp
#include <iostream>
using namespace std;

// Control Statement
// - if, if-else / if-else if-else
// - while, for, do-while
// - switch
#if 0
int main()
{
    int x[5] = {10, 20, 30, 40, 50}; // 컨테이너, 컬렉션

    constexpr size_t len = sizeof(x) / sizeof(x[0]);
    for (int i = 0; i < len; ++i)
    {
        cout << x[i] << endl;
    }

    // C++11, Ranged-for
    for (auto e : x)
    {
        cout << e << endl;
    }
}
#endif

// 컨테이너: STL이 제공하는 자료구조
//   선형 자료 구조 - vector / list
#include <vector>
#include <list>

#if 0
int main()
{
    vector<int> v = {10, 20, 30}; // 3 * 4 = 12byte

    cout << v.size() << ", " << v.capacity() << endl; // 3, 3

    // 배열과 동일하게 인덱스를 기반으로 요소에 접근할 수 있습니다.
    v[0] = 100;
    v[1] = 200;
    v[2] = 300;

    // v[3] = 100; /* 잘못된 메모리 접근! 미정의 동작! */
    v.push_back(10); // 더 큰 메모리를 할당해서, 기존 데이터를 복사합니다. 그리고 데이터를 추가합니다.
    cout << v.size() << ", " << v.capacity() << endl;
    v.push_back(20);
    cout << v.size() << ", " << v.capacity() << endl;
    v.push_back(30);
    cout << v.size() << ", " << v.capacity() << endl;

    // vector - 동적 배열
    //   데이터를 계속 추가할 수 있습니다.

    for (auto e : v)
    {
        cout << e << endl;
    }
}
#endif

#if 0
// https://devdocs.io/
// * LLM - MCP(Model Context Protocol) - Context7
int main()
{
    vector<int> v;
    v.reserve(100); // 불필요한 재할당과 복사를 예방하기 위해서 사용합니다.

    for (int i = 0; i < 100; ++i)
    {
        v.push_back(i);
        cout << v.size() << ", " << v.capacity() << endl;
    }

    v.resize(0);
    cout << v.size() << ", " << v.capacity() << endl;
    v.shrink_to_fit(); // 할당된 용량을 조정하는 기능을 제공하고 있습니다. C++11
    cout << v.size() << ", " << v.capacity() << endl;
}
#endif

#if 0
// Type deduction - auto
int main()
{
    vector<int> v = {10, 20, 30};

    for (auto &e : v)
    {
        e += 10;
    }

    for (auto e : v)
    {
        cout << e << endl;
    }
}
#endif

#if 0
int main()
{
    int a = 10;  // a의 타입은? int
    auto a2 = a; // a2의 타입은? int

    const int b = 10; // b의 타입은? const int
    auto b2 = b;      // auto에서 const는 따라오지 않습니다.
    b2 = 100;         /* OK */

    const auto b3 = b; // b3는 const int 입니다.

    int n = 10;
    int &r = n; // r의 타입은? int&
    r = 100;
    cout << n << endl; // 100

    auto r2 = r;  // r2의 타입은? &도 따라오지 않습니다. int
    auto &r3 = r; // r3는 r의 메모리를 접근하는 새로운 이름으로 동작합니다.
}
#endif

#if 1
// 실패 가능성이 있는 함수를 사용한 경우,
// 반드시 실패를 확인하고, 처리해야 합니다.
int Process1()
{
    // 성공하면 0, 실패시 0이 아닌 값을 반환합니다.
    return 0;
}

int Process2()
{
    return 0;
}

enum TaskState
{
    RUNNING,
    STOPPED,
    WAITING
};

TaskState GetState() { return TaskState::RUNNING; }

// C++17, If/Switch Statement with Initializer
int main()
{

    switch (TaskState state = GetState(); state)
    {
    case TaskState::RUNNING:
        break;
    case TaskState::STOPPED:
        break;
    case TaskState::WAITING:
        break;
    default:
        break;
    }

    if (int ret = Process1(); ret != 0)
    {
        // ...
    }

    if (int ret = Process2(); ret != 0)
    {
        // ...
    }
}
#endif