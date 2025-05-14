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

#if 0
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
#endif

// 객체가 메모리에 생성되었을 때, 호출되는 약속된 멤버 함수가 있습니다.
// => 생성자(Constructor) 함수
//  - 클래스이름과 동일한 이름의 멤버 함수 입니다.
//  - 반환값도 없고, 반환 타입도 명시하지 않습니다.

#if 0
class Stack
{
private:
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
    Stack s1;

    s1.Push(10);
    s1.Push(20);
    s1.Push(30);

    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
}
#endif

#if 0
class Stack
{
private:
    // int buff[10];
    int *buff;
    int top;

public:
    // Stack()
    // {
    //     buff = new int[10];
    //     top = 0;
    // }

    // 불필요한 오버로딩을 제거할 수 있는 경우가 있습니다.
    Stack(int size = 10)
    {
        buff = new int[size];
        top = 0;
    }

    // 객체가 메모리에서 파괴되기 전에 호출되는 약속된 멤버함수
    // => 소멸자(Destructor) 함수
    //  ~클래스이름 입니다.
    //   인자는 없습니다.
    //   반환값도 없고, 반환 타입도 명시하지 않습니다.
    //   오직 한개만 제공할 수 있습니다.
    ~Stack()
    {
        delete[] buff;
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
    Stack s1{100};
    // Stack s1;

    s1.Push(10);
    s1.Push(20);
    s1.Push(30);

    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
}
#endif

template <typename TYPE>
class Stack
{
private:
    TYPE *buff;
    int top;

public:
    Stack(int size = 10)
    {
        buff = new TYPE[size];
        top = 0;
    }

    ~Stack()
    {
        delete[] buff;
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

int main()
{
    // 클래스 템플릿은 명시적으로 타입을 지정해야 하는
    // 경우가 많습니다.
    Stack<int> s1{100};

    s1.Push(10);
    s1.Push(20);
    s1.Push(30);

    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
    cout << s1.Pop() << endl;
}