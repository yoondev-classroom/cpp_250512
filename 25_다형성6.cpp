// 25_다형성6.cpp
#include <iostream>
using namespace std;

class Car
{
public:
    virtual void Start() { cout << "Car::Start()" << endl; }
};

class Sedan : public Car
{
public:
    // Sedan의 모든 자식 클래스는 반드시 아래 함수를 이용해야 합니다.
    // => C++11, final
    void Start() override final { cout << "Sedan::Start()" << endl; }
};

// final을 클래스 뒤에 사용하면, 상속이 금지됩니다.
class Avante final : public Sedan
{
public:
    // void Start() override { cout << "Avante::Start()" << endl; }
};

// class NewAvante : public Avante {};
// - final 클래스는 상속이 금지됩니다.

int main()
{
    Sedan s;
    // s.Start();

    Car *p = &s;
    p->Start();

    Avante a;
    p = &a;
    p->Start();
}