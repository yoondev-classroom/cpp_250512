// 13_stack5.cpp
#include <iostream>
using namespace std;

// 사용자가 원하는 크기의 스택을 생성하고 싶습니다.
// => 객체를 생성할 때, 사용자로부터 정보를 전달받을 수 있습니다.
//   "생성자 인자"

class Stack
{
    // int buff[10];
    int *buff;
    int top;

public:
    Stack(int size)
    {
        buff = new int[size];
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
    Stack s2{100};

    Stack s{10};

    s.Push(10);

    s.Push(20);
    s.Push(30);

    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
}

#if 0
class Stack
{
public:
    // 생성자 오버로딩이 가능합니다.
    Stack() {}
    Stack(int n) {}
    Stack(int a, int b) {}
};

int main()
{
    Stack s1{10, 20}; // Stack(int, int)
    Stack s2{42};     // Stack(int)
    Stack s3;         // Stack()
}
#endif