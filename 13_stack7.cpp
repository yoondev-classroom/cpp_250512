// 13_stack7.cpp
#include <iostream>
using namespace std;

#include <string>

// 클래스 템플릿
template <typename TYPE>
class Stack
{
    TYPE *buff;
    int top;

public:
    ~Stack()
    {
        cout << "~Stack()" << endl;
        delete[] buff;
    }

    Stack(int size)
    {
        buff = new TYPE[size];
        top = 0;
    }

    void Push(TYPE n)
    {
        buff[top++] = n;
    }

    TYPE Pop()
    {
        return buff[--top];
    }
};

// 클래스 템플릿은 암묵적으로 타입을 결정하기 어려울 수 있습니다.
// 명시적으로 타입을 지정해야 합니다.
int main()
{
    Stack<string> s1{10};
    s1.Push("hello");
    s1.Push("world");

    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;

    Stack<int> s{10};

    s.Push(10);
    s.Push(20);
    s.Push(30);

    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
}
