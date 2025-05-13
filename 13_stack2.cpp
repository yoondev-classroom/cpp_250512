// 13_stack2.cpp
#include <iostream>
using namespace std;

// 데이터 캡슐화

// 해결방법: 스택의 상태를 사용자 정의 타입(구조체)으로 설계합니다.
#if 1
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
    // buff[top++] = n;
    s->buff[(s->top)++] = n;
}

int Pop(Stack *s)
{
    // return buff[--top];
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

    Stack s2;
    Init(&s2);
}
#endif

// 구조체 타입의 크기는 멤버의 크기에 의해서 결정됩니다.
struct Point
{
    int x;
    int y;
};

#if 0
void Print(Point pt)
{
    cout << pt.x << ", " << pt.y << endl;
}

int main()
{
    cout << sizeof(Point) << endl;

    Point pt1;

    pt1.x = 10;
    pt1.y = 20;

    Print(pt1);
}
#endif

#if 0
void Print(const Point *pt)
{
    // (*pt).x = 1000; // 오류!

    // cout << (*pt).x << ", " << (*pt).y << endl;
    cout << pt->x << ", " << pt->y << endl;
}

int main()
{
    cout << sizeof(Point) << endl;

    Point pt1;

    pt1.x = 10;
    pt1.y = 20;

    Print(&pt1);
}
#endif