// 25_다형성5.cpp
#include <iostream>
using namespace std;

// 1) 자식이 재정의한 부모의 멤버 함수가 가상 함수이면,
//    자식의 멤버함수도 가상함수가 됩니다.

// 2) 부모가 제공하는 멤버 함수가 가상함수가 아닐 경우,
//    재정의하면 안됩니다.
//   => virtual이 아닌데, 오버라이딩 하는 경우
//      부모의 멤버 함수를 잘못 사용해서, 오버라이딩이 아니라,
//      새로운 멤버 함수를 만드는 경우
//   => 해결방법
//     C++11, override

class Animal
{
public:
    virtual void Cry() const { cout << "Animal::Cry()" << endl; }
};

class Dog : public Animal
{
public:
    void Cry() const override { cout << "Dog::Cry()" << endl; }
};

int main()
{
    Dog d;

    Animal *p = &d;
    p->Cry();

    Animal &r = d;
    r.Cry();
}