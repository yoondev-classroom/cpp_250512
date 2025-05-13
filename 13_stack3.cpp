// 13_stack3.cpp
#include <iostream>
using namespace std;

// 원인: C언어에서는 캡슐화를 할때,
//      데이터만 캡슐화할 수 있습니다.
//      그래서, 전역 함수를 통해 어떤 상태인지를
//      명시적으로 전달받아야 합니다.

// 해결방법
// : C++에서는 데이터와 데이터를 조작하는 함수를
//   캡슐화 할 수 있습니다.

struct Stack
{
    // 상태
    int buff[10];
    int top;

    // 상태를 조작하는 함수
    void Init()
    {
        top = 0;
    }

    void Push(int n)
    {
        buff[top++] = n;
    }

    int Pop()
    {
        return buff[--top];
    }
};

int main()
{
    Stack s;
    s.Init();

    s.Push(10);
    s.Push(20);
    s.Push(30);

    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
}