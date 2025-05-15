// 26_가상함수의원리.cpp
#include <iostream>
using namespace std;

// 1) 가상함수를 가지는 모든 객체의 크기가 포인터 크기(8바이트) 만큼 증가합니다.
// 2) 가상함수의 개수만큼 가상 함수 테이블의 메모리 비용이 소모됩니다.

class Shape
{
    int x;
    int y;

public:
    virtual void Draw() const { cout << "Shape::Draw" << endl; }
};

class Rect : public Shape
{
    long color;

public:
    virtual void Draw() const { cout << "Rect::Draw" << endl; }
};

int main()
{
    Shape s;
    Rect r;

    Shape *p = &s;
    p->Draw();

    p = &r;
    p->Draw();

    cout << sizeof(s) << endl; // 8
    cout << sizeof(r) << endl; // 16
}