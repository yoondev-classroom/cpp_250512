// 13_stack6.cpp
#include <iostream>
using namespace std;

// 객체 내부에서 new를 통해 메모리를 할당하였다면,
// 해당 객체가 메모리에서 파괴되기 전에, 반드시 delete를 통해 해지해주어야 합니다.
// => 객체가 메모리에서 파괴되기 직전에 호출되는 약속된 멤버 함수가 존재합니다.
//    소멸자(Destructor) 함수
// => 이름이 ~클래스 이름과 동일합니다.
//    반환값도 없고, 반환타입도 명시하지 않습니다.
//    소멸자는 인자가 없습니다.
//    오직 1개만 제공할 수 있습니다.

class Stack
{
    // int buff[10];
    int *buff;
    int top;

public:
    // 소멸자
    ~Stack()
    {
        cout << "~Stack()" << endl;
        delete[] buff;
    }

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