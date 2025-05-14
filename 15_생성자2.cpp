// 15_생성자2.cpp
#include <iostream>
using namespace std;

class Object
{
public:
    Object() { cout << "Object()" << endl; }
    ~Object() { cout << "~Object()" << endl; }
};

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
    Point *p1 = new Point; // Point()
    Point *p2 = new Point{10, 20};

    Point *p3 = new Point[3]{
        {10, 20},
        {},
        {10, 20},
    };
}