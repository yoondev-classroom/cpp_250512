// 25_다형성4.cpp
#include <iostream>
using namespace std;

// 오버라이딩(Overriding)
// 정의: 부모 클래스가 제공하는 멤버 함수를 자식 클래스가 재정의할 수 있습니다.

// * 자식이 재정의(오버라이딩) 하는 멤버 함수는 반드시 가상이어야 합니다.

class Animal
{
public:
    virtual void Cry() const { cout << "Animal::Cry()" << endl; }
};

class Dog : public Animal
{
public:
    virtual void Cry() const { cout << "Dog::Cry()" << endl; }
};

// 바인딩(Binding)
// - p->Cry()를 호출할 때, 어떤 클래스의 멤버 함수로
//   호출될지 결정하는 것

// 1) 정적 바인딩(static binding) / 컴파일 타임
//  => 어떤 함수를 호출할지 컴파일 시간에 컴파일러가 결정합니다.
//     p->Cry()
//     p의 타입을 보고, 결정합니다.

// 2) 동적 바인딩(dynamic binding) / 런타임
// => 어떤 함수를 호출할지 컴파일러가 실행 시간에 조사해서 호출하는 코드를
//    삽입합니다.
//    p->Cry()

int main()
{
    Animal a;
    Dog d;

    Animal *p = &a;
    p->Cry();

    p = &d;
    p->Cry();
}

#if 0
int main()
{
    Animal a;
    Dog d;

    a.Cry();
    d.Cry();
}
#endif