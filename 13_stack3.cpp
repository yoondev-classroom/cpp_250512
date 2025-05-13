// 13_stack3.cpp
#include <iostream>
using namespace std;

// 원인: C언어에서는 캡슐화를 할때,
//      데이터만 캡슐화할 수 있습니다.
//      그래서, 전역 함수를 통해 어떤 상태인지를
//      명시적으로 전달받아야 합니다.

// 해결방법
// : C++에서는 데이터와 데이터를 조작하는 함수를
//   캡슐화(상태 + 행위) 할 수 있습니다.

// 객체의 상태는 외부에서 함부로 조작되는 것이 위험합니다.
// => 객체의 상태는 객체가 제공하는 메소드(멤버 함수)를 통해서만 접근 가능해야 합니다.
// => 정보 은닉(Information Hiding)

// public: 외부에서 접근이 가능합니다.
// private: 외부에서 접근이 불가능합니다.

// struct는 기본 접근 지정자가 public 입니다.
// class는 기본 접근 지정자가 private 입니다.
// => C++ 에서 객체를 캡슐화할 때, 일반적으로 class를 사용하는 것이 좋습니다.

// struct Stack
class Stack
{
    // private:
    // 상태 - 멤버 데이터
    int buff[10];
    int top;

public:
    // 상태를 조작하는 함수 - 멤버 함수 / 메소드
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
    // 상태와 행위를 가지는 변수
    // => 객체(object)
    // s.top = -1; // !!!

    s.Init();

    s.Push(10);

    s.Push(20);
    s.Push(30);

    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
}