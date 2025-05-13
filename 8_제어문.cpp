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