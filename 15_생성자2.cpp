// 15_생성자2.cpp
#include <iostream>
using namespace std;

class Object
{
public:
    Object() { cout << "Object()" << endl; }
    ~Object() { cout << "~Object()" << endl; }
};

// new 연산
// 1) 메모리 할당
// 2) 객체라면, 생성자 호출

// delete 연산
// 1) 객체라면, 소멸자 호출
// 2) 메모리 해지

#if 0
int main()
{
    // Object obj;

    // Object *p = static_cast<Object *>(malloc(sizeof(Object)));
    // malloc을 통해 객체를 생성할 경우, 생성자가 호출되지 않습니다.
    // free(p);
    // free를 통해 객체의 메모리를 해지할 경우, 소멸자가 호출되지 않습니다.

    Object *p = new Object;
    // new를 통해 객체를 생성할 경우, 생성자가 호출됩니다.
    delete p;
    // delete를 통해 객체의 메모리를 해지한 경우, 소멸자가 호출됩니다.
}
#endif

#if 0
int main()
{
    Object *p = new Object[3];

    delete[] p;
}
#endif

class Point
{
public:
    Point() { cout << "Point()" << endl; }
    Point(int x, int y) { cout << "Point(int, int)" << endl; }
};

int main()
{
    // int *p = new int; // 쓰레기값
    int *p = new int{42};

    Point *p1 = new Point; // Point()
    Point *p2 = new Point{10, 20};

    Point *p3 = new Point[3]{
        {10, 20},
        {},
        {10, 20},
    };
}