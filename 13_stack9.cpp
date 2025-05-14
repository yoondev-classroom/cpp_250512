// 13_stack9.cpp
#include <iostream>
using namespace std;

#if 0
int buff[10];
int top = 0;

void Push(int n)
{
    buff[top++] = n;
}

int Pop()
{
    return buff[--top];
}

int main()
{
    Push(10);
    Push(20);
    Push(30);

    cout << Pop() << endl;
    cout << Pop() << endl;
    cout << Pop() << endl;
}
#endif

#if 0
struct Stack
{
    int buff[10];
    int top;
};

void Init(Stack *s)
{
    s->top = 0;
}

void Push(Stack *s, int n)
{
    s->buff[(s->top)++] = n;
}

int Pop(Stack *s)
{
    return s->buff[--(s->top)];
}

int main()
{
    Stack s1;
    Init(&s1);

    Push(&s1, 10);
    Push(&s1, 20);
    Push(&s1, 30);

    cout << Pop(&s1) << endl;
    cout << Pop(&s1) << endl;
    cout << Pop(&s1) << endl;
}
#endif

// 캡슐화(상태 + 행위)
// - 정보 은닉 => 접근 지정자
//    1) public: 외부에서 접근이 가능합니다.
//    2) private: 외부에서 접근이 불가능하고, 제공되는 멤버 함수를 통해서만 접근할 수 있습니다.

// - struct: 기본 접근 지정자가 public 입니다.
// -  class: 기본 접근 지정자가 private 입니다.
class Stack
{
private:
    // 멤버 데이터
    int buff[10];
    int top;

public:
    // 멤버 함수 / 메소드
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
    Stack s1;
    s1.Init();

    // s1.top = -1;

    s1.Push(10);
    s1.Push(20);
    s1.Push(30);

    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
}