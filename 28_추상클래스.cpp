// 28_추상클래스.cpp
#include <iostream>
using namespace std;

class Shape
{
public:
    // 순수 가상 함수(pure virtual function)
    // - 부모의 입장에서 구현할 필요가 없습니다.
    // - 자식 클래스는 반드시 해당 기능을 오버라이딩(재정의)해야 합니다.
    // - 순수 가상 함수를 가지는 클래스는 객체를 생성(인스턴스화)할 수 없습니다.
    //   => 추상 클래스가 됩니다.
    virtual void Draw() const = 0;
    virtual ~Shape() {}
};

class Rect : public Shape
{
public:
    // 자식 클래스가 부모가 제공하는 순수 가상 함수를 재정의하지 않으면,
    // 자식 클래스도 추상 클래스가 됩니다.
    void Draw() const override { cout << "Draw Rect" << endl; }
};

int main()
{
    // Shape s;
    Rect r;
}