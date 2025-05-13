// 13_stack2.cpp
#include <iostream>
using namespace std;

// 해결방법: 스택의 상태를 사용자 정의 타입(구조체)으로 설계합니다.
#if 0
struct Stack
{
    int buff[10];
    int top;
};

void Push(Stack *s, int n)
{
}

int Pop(Stack *s)
{
}

int main()
{
    Stack s1;
    Push(&s1, 10);
    Push(&s1, 20);
    Push(&s1, 30);

    cout << Pop(&s1) << endl;
    cout << Pop(&s1) << endl;
    cout << Pop(&s1) << endl;

    Stack s2;
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