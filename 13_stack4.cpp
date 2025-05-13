// 13_stack4.cpp
#include <iostream>
using namespace std;

// 객체가 생성되면, 객체는 사용할 수 있는 상태가 되어야 합니다.
// => 객체가 메모리에 생성되면, 자동으로 호출되는 약속된 멤버 함수가 있습니다.
// => 생성자(Constructor) 함수
//    "초기화"

// * 생성자
//   1) 클래스 이름과 동일한 이름을 가지고 있습니다.
//   2) 반환 타입도 명시하지 않고, 반환값도 존재하지 않습니다.
class Stack
{
    int buff[10];
    int top;

public:
    Stack()
    {
        cout << "Stack()" << endl;
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

    s.Push(10);

    s.Push(20);
    s.Push(30);

    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
}
